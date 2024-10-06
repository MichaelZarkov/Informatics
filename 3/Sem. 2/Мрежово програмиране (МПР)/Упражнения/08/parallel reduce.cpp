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
#include <execution>
#include <shared_mutex>
#include <future>
#include <cstdlib>
#include <cassert>
#include <type_traits>
#include <format>
using namespace std;

uint32_t min_element_count = 1'000'000'000 / (std::thread::hardware_concurrency() * 16);


template <typename iterator>
inline uint64_t constexpr parallel_reduce(iterator begin, iterator end) noexcept {
	uint32_t length = std::distance(begin, end);

	if (length <= min_element_count)
		return std::reduce(begin, end, 0);

	iterator mid = begin;
	std::advance(mid, (length + 1) / 2);


	std::future <uint64_t> f1 = std::async(std::launch::async, parallel_reduce <iterator>, mid, end);
	std::future <uint64_t> f2 = std::async(std::launch::async, parallel_reduce <iterator>, begin, mid);

	return f2.get() + f1.get();
}

int main() {
	uint64_t result_std_parallel, result_parallel;


	std::srand(std::time(nullptr)); // use current clock time
	std::chrono::duration <double, std::milli> ms;
	std::vector <uint8_t> v(1'000'000'000, 1);
	uint64_t sum1 = 0;


	const auto t3 = std::chrono::high_resolution_clock::now();
	for (uint8_t i = 0; i < 10; ++i) {
		v[i * 11 + 7 + rand() ^ 2] = 17 * rand();
		v[i * 6 + 11 + rand() ^ 2] = 14 * rand();
		v[i * 54 + 14 + rand() ^ 2] = 36 * rand();
		v[i * 785 + 5 + rand() ^ 2] = 4 * rand();
		uint64_t result_parallel = parallel_reduce(v.begin(), v.end());
		//std::cout << result_parallel << '\n';


	}
	const auto t4 = std::chrono::high_resolution_clock::now();
	ms = t4 - t3;
	std::cout << "     Parallel reduce result took:    " << ms.count() << " ms\n";


	
	const auto t1 = std::chrono::high_resolution_clock::now();
	for (uint8_t i = 0; i < 10; ++i) {
		v[i * 15 + 7 + rand() ^ 2] = 5 * rand();
		v[i * 6 + 11 + rand() ^ 2] = 17 * rand();
		v[i * 33 + 14 + rand() ^ 2] = 19 * rand();
		v[i * 105 + 5 + rand() ^ 2] = 8 * rand();
		 result_std_parallel = std::reduce(std::execution::par, v.begin(), v.end(), 0, std::plus<>{});


	}
	const auto t2 = std::chrono::high_resolution_clock::now();
	ms = t2 - t1;
	std::cout << "Std Parallel reduce result took:    " << ms.count() << " ms\n";
	
	
	





	return 0;
}
