#include <ctime>
#include <iostream>
#include <chrono>
auto startTime = std::chrono::high_resolution_clock::now();
auto endTime = std::chrono::high_resolution_clock::now();
std::chrono::duration<double, std::milli> ms;
int main()
{
	const size_t RowsCount = 14000;
	const size_t ColsCount = 300000;
	
	int* parr = new int[RowsCount * ColsCount];

	size_t row, col;
	unsigned long long sum;

	startTime = std::chrono::high_resolution_clock::now();

	for (row = 0; row < RowsCount; ++row)
		for (col = 0; col < ColsCount; ++col)
			parr[ColsCount * row + col] = static_cast<int>(row);

	endTime = std::chrono::high_resolution_clock::now();
	ms = endTime - startTime;
	std::cout << "Initalizion of elements took: " << ms.count() <<"ms"<< std::endl;




	sum = 0;
	startTime = std::chrono::high_resolution_clock::now();

	for (col = 0; col < ColsCount; ++col)
		for (row = 0; row < RowsCount; ++row)
			sum += parr[ColsCount * row + col];

	endTime = std::chrono::high_resolution_clock::now();
	ms = endTime - startTime;
	std::cout << "\nIterating by columns took: " << ms.count() << "ms" << "\n    sum is " << sum << "\n\n";



	sum = 0;
	startTime = std::chrono::high_resolution_clock::now();

	for (row = 0; row < RowsCount; ++row)
		for (col = 0; col < ColsCount; ++col)
			sum += parr[ColsCount * row + col];

	endTime = std::chrono::high_resolution_clock::now();
	ms = endTime - startTime;
	std::cout << "\nIterating by rows took: " << ms.count() << "ms"<< "\n    sum is " << sum << "\n\n";

	delete[] parr;

	return 0;
}