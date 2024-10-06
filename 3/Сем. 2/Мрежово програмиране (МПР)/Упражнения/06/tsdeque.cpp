#include <iostream>
#include <mutex>
#include <deque>
#include <queue>
#include <thread>
#include <vector>
#include <functional>
#include <chrono>
#include <string>
#include <algorithm>
#include <numeric>
#include <future>
#include <execution>
#include <iomanip>
#include <utility>
#include <iterator>
#include <shared_mutex>
#include <type_traits>
#include <cassert>
using namespace std;

template <typename T>
requires(is_trivially_copyable_v<T>)
struct ms {
	T a;
	T b;
	ms(T _a, T _b) : a(_a), b(_b) {};
	//ms() = default;
	//ms(const ms& other) {
	//	a = other.a;
	//	b = other.b;

	//}

};

template <typename T>
class tsdeque {
private:
	std::mutex deq_mutex;
	std::shared_mutex deq_shared_mutex;
	std::deque <T> deq;
	using unique_lockk = std::unique_lock <std::mutex>;
	using shared_lockk = std::shared_lock <std::shared_mutex>;

public:

	tsdeque() = default;
	tsdeque(const deque <T>&) = delete;
	virtual ~tsdeque() { clear(); }

	const T& front() {

		shared_lockk lock(deq_shared_mutex);
		return deq.front();
    }


	 T pop_front() {
		 unique_lockk lock(deq_mutex);
		 T t = std::move(deq.front());
		 deq.pop_front();

		 return t;

	 }
    
	 T pop_back() {

		 unique_lockk lock(deq_mutex);
		 T t = std::move(deq.back());
		 deq.pop_back();

		 return t;
	 }

	 void push_back(const T& item) {
		 //comment the line below to enforce race condition
		 unique_lockk lock(deq_mutex);
		 deq.push_back(item);

	 }

	 void push_front (const T& item) {
		 unique_lockk lock(deq_mutex);
		 deq.push_front(item);

	 }

	 void clear() {

		 unique_lockk lock(deq_mutex);
		 deq.clear();
	 }

	 bool empty() {

		 shared_lockk lock(deq_shared_mutex);
	     return deq.empty();

	 }
 
};





typedef  ms <int_fast32_t > my_struct ;
tsdeque <my_struct > deq;


int main() {

    static_assert (is_trivially_copyable_v <ms <int>> == true);
	static_assert (is_trivially_copy_assignable_v <ms <int>> == true);
	static_assert (is_trivially_copy_constructible_v <ms <int>> == true);

	int c = 5;

	std::function <void(ms <int_fast32_t> )> lambda = [](ms <int_fast32_t> value) {

		deq.push_back(value);
	};

	void (*func) (my_struct );

	func = [](my_struct  value) {

		deq.push_back(value);
	};

	vector <future <void >> VF;

	for (int i = 0; i < 1000; ++i)
	{
		ms <int> obj{ i,i};
		//comment line 79 to enforce race condition

		//function pointer
		//VF.push_back(std::async(func, obj ));
		

		//std::function
	    VF.push_back(std::async(lambda, obj));


	}

	//sync all threads in parallel,
	//make sure to use c++20 or later
    //std::for_each( VF.begin(), VF.end(), [](future <void>& x) {x.get(); });

	for (future <void>& x : VF)
		   x.get();


	while (!deq.empty()) {
		ms <int> value = deq.pop_back();
		cout << value.a << " " << value.b << '\n';


	}

	


	return 0;
}
