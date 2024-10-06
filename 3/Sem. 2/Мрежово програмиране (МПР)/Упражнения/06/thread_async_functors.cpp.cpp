#include <iostream>
#include <numeric>
#include  <thread>
#include <future>
#include <vector>
#include <execution>
using namespace std;

void Summ(uint64_t& sum, uint64_t start_index, uint64_t end_index) {

	sum = 0;
	for (uint64_t i = start_index; i < end_index; ++i)
		sum += i;

}


uint64_t Return_Sum(uint64_t start_index, uint64_t end_index) {

	uint64_t sum = 0;
	for (uint64_t i = start_index; i < end_index; ++i)
		sum += i;


		return sum;


}



class Functor {

public:
	void operator () (uint64_t start, uint64_t end) {
		_sum = 0;

		for (uint64_t i = start; i < end; ++i)
			_sum += i;


	}

	uint64_t _sum;

};


int main() {

	uint64_t number_of_threads = 20;
	uint64_t number_of_elements = 2'000'000'000;
	uint64_t step =number_of_elements / number_of_threads;

   //thread (Summ)
	std::vector <std::thread> threads;
	std::vector <uint64_t> partial_sum(number_of_threads);

	//async ( Return_Sum)
	std::vector <future <uint64_t> > VF;


	// thread (Functor )
	std::vector <std::thread> functor_threads;
	std::vector <Functor*> functors;



	//thread
	for (uint64_t i = 0; i < number_of_threads; ++i) {

		threads.push_back(std::thread(Summ, std::ref(partial_sum[i]), i * step, (i + uint64_t(1)) * step));

	}
	//sync 20 threads
	for (std::thread& t : threads)
		t.join();

	uint64_t total = std::reduce(std::execution::par, partial_sum.begin(), partial_sum.end(), uint64_t(0));



	for (uint64_t i = 0; i < number_of_threads; ++i) {

		VF.push_back(std::async(Return_Sum, i * step, (i + uint64_t(1)) * step));
	}

	uint64_t result = 0;

	for (std::future <uint64_t>& t : VF)
		result += t.get();
	
	for (uint64_t i = 0; i < number_of_threads; ++i) {
		Functor* functor = new Functor();
		functor_threads.push_back(std::thread(std::ref(*functor), i * step, (i + uint64_t(1)) * step));

		functors.push_back(functor);

	}

	for (std::thread& t : functor_threads) {

		t.join();
	}

	uint64_t functor_sum=0;

	for (auto pf : functors) {
		functor_sum += pf->_sum;
	}


	std::cout << "Result from  thread:   " << total << '\n';
	std::cout << "Result from  async:    " << result << '\n';
	std::cout << "Result from  functors: " << functor_sum << '\n';

		 





	return 0;
}