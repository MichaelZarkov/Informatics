#include <iostream>
#include <thread>
#include <vector>
#include <functional>
#include <mutex>
#include <atomic>
#include <condition_variable>
#include <chrono>
#include <vector>
#include <numeric>
#include <iostream>
#include <cstring>
#include <cmath>
//#include <execution>



using namespace std;


template<typename T>
int length1(const T& value) noexcept {
	if constexpr (std::is_integral<T>::value)  // is number
		return std::floor(std::log10(value)) + 1;
	else
		return value.length();
	
}




//int x = 0;
mutex glock;
std::condition_variable gCondition;
//conditional variable - eliminates excess cpu cycles for other threads constantly asking if they can obtain the lock

//static atomic <int> x = 0;
int x = 0;


int main() {

	auto lambda = []()
	{
		
	// std::lock_guard <std::mutex> lockg(glock);
		//lock_guard is mutex wrapper (destroying the mutex when it's out of scope)

     //std::scoped_lock <std::mutex> scopedlock(glock);
		// 
		// 
		// scoped_lock is newer version of lock_guard which can lock more than one mutex at a time

		 //glock.lock(); 
		// not working for try and catch blocks
	

		//critical section
		{
			std::scoped_lock <std::mutex> scopedlock(glock);
			x++;
			x = x + 1;

		}
			
			// not working for atomic - implemented in hardware
	
		
		//glock.unlock();
		
	};

	

	int a = 56546;
	string b = "foo";
	std::cout << length1(a) << endl << length1(b)<<endl;




	vector<thread> t;
	for (int i = 0; i < 1000; ++i)
	{
		t.push_back(thread(lambda));
		//t[i].join(); - not running in parallel

	}

	for (int i = 0; i < 1000; ++i)
		t[i].join();
	
	cout << x << std::endl;
	



	//std::thread t(worker);
	//std::cout << "main thread" << std::endl;
	//t.join();


	int result = 0;
	bool notified = false;

	//Reportring thread
	std::thread reported([&] {
		//conditional variable works only with unique_lock
		std::unique_lock <std::mutex>lock(glock);
		if (!notified) {

			gCondition.wait(lock);
		}
		std::cout << "Reported result is " << result<<std::endl;
		});


	// Working thread
	// conditional variable requires unique_lock
	// lock_guard has less features than unique_lock
	// unique_lock can transfer ownership

	std::thread worker([&] {

		std::unique_lock <std::mutex> lock(glock);
		//unique_lock is more has more features compared to lock_guard/scoped_lock
		//do our work
		result = 42*42;
		notified = true;
		std::this_thread::sleep_for(std::chrono::seconds(5));
		std::cout << "Work completed\n";
		gCondition.notify_one();

		});
	//conditional variable - eliminates excess cpu cycles for other threads constantly asking if they can obtain the lock
	reported.join();
	worker.join();

	return 0;
}