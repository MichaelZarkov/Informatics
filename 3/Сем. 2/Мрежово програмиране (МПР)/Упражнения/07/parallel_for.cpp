#include <iostream>
#include <chrono>
#include <execution>
#include <future>
#include <shared_mutex>
#include <thread>

using namespace std;

int testSize = 1'000'000;
//int min_per_thread = 1'000'000 / (std::thread::hardware_concurrency() * (1 << 3));
int min_per_thread = 1'000'000 / 128;
template <typename Iterator,typename Func >
inline void constexpr parallel_for(Iterator first, Iterator last, Func f) {
	
	int length = std::distance(first, last);
	if (!length)
		return;

	if (length <= min_per_thread) {
		std::for_each(first, last, f);

	}
	else {
		Iterator mid_point = first + length / 2;
		std::future <void> first_half =
			std::async(std::launch::async, &parallel_for <Iterator, Func>, first, mid_point, f);
		std::future <void> second_half =
			std::async(std::launch::async, &parallel_for <Iterator, Func>, mid_point, last, f);

		first_half.get();
		second_half.get();

	}



}

auto functionn = [](const int& n) {

	int sum = 0;
	for (auto i = 0; i < 30000; i++)
		sum += i % 11;


	sum += n << 2;

};

int main() {
	std::chrono::duration <double, std::milli>ms;
	std::vector <int> ints(testSize,1);

	auto startTime = std::chrono::high_resolution_clock::now();
	auto endTime = std::chrono::high_resolution_clock::now();

		for (int j = 0; j < 10; ++j) {
		auto startTime = std::chrono::high_resolution_clock::now();
		parallel_for(ints.cbegin(), ints.cend(), functionn);
		
		endTime = std::chrono::high_resolution_clock::now();

		ms = endTime - startTime;
		std::cout << "Parallel async: " << ms.count() << std::endl;

		 startTime = std::chrono::high_resolution_clock::now();
		std::for_each(std::execution::par, ints.cbegin(), ints.cend(), functionn);
		endTime = std::chrono::high_resolution_clock::now();

		ms = endTime - startTime;
		std::cout << "STL-par      : " << ms.count() << std::endl;
		


	 }

		return 0;
}