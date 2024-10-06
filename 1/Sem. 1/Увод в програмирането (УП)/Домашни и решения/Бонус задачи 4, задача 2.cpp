// Bonust zadachi 4, zadacha 2

#include <iostream>

// Checks if a number is prime and if ('N' - 1) is devisible by 7
bool test(int N) {
	if (N == 1 || (N - 1) % 7 != 0)
		return false;

	if (N % 2 == 0)
		return false;

	for (int i = 3; i * i <= N; i += 2)
		if (N % i == 0)
			return false;
		
	return true;
}

// Checks which elements in an array pass a condition
// Puts the elements which pass in an array
// Returns a pointer to the new array
int* testElements(int* array, size_t size, size_t new_size) {
	bool a = false;
	
	// Test if the condition is true
	if (test(array[size - 1])) {
		++new_size;
		a = true;
	}
		
	// Reach the last element
	if (size == 1) {
		int* new_array = new(std::nothrow) int[new_size];
		if (!new_array) {
			std::cout << "\nFail to allocate memory for 'new_array'.\n";
			return nullptr;
		}

		new_array += new_size;

		// If the current element passes the condition, put it in the new array
		if (a) {
			*(new_array - 1)= array[size - 1];
			return (new_array - 1);
		}

		return array;
	}

	int* new_array = testElements(array, size - 1, new_size);
	if (!new_array)
		return nullptr;

	if (a) {
		*(new_array - 1) = array[size - 1];
		return (new_array - 1);
	}

	return array;
}

// Finds the count of even numbers in an array
int countOfEvenNumbers(int* array, size_t size) {
	int count = 0;
	if (array[size - 1] % 2 == 0)
		++count;
	if (size == 1)
		return count;

	count += countOfEvenNumbers(array, size - 1);
	return count;
}

// Finds the smallest element in an array
int minimumOfArray(int* array, size_t size, int min) {
	
	if (min > array[size - 1])
		min = array[size - 1];
	if (size == 1)
		return min;

	min = minimumOfArray(array, size - 1, min);
	return min;
}

// Calculates sum of the elements of an array with recursion
int sumOfArray(int* array, size_t size) {
	int sum = array[size - 1];

	if (size == 1)
		return sum;
	
	sum += sumOfArray(array, size - 1);
	return sum;
}

void recursionArray() {

	// Input size
	size_t size;
	do {
		std::cout << "Size of the array = ";
		std::cin >> size;
		if (size < 1)
			std::cout << "'Size' must be a natural number. Try again.";
	} while (size < 1);

	// Allocate array
	int* array = new(std::nothrow) int[size];
	if (!array) {
		std::cout << "Fail to allocate memory.";
		return;
	}

	// Input array
	for (size_t i = 0; i < size; ++i)
		std::cin >> array[i];

	std::cout << "\nSum of the elements = " << sumOfArray(array, size);

	std::cout << "\nSmallest element = " << minimumOfArray(array, size - 1, array[size - 1]);

	std::cout << "\nCount of even numbers = " << countOfEvenNumbers(array, size);

	int* new_array = testElements(array, size, 0);		// !!! Unfinished! Has to return size of the array. !!!

	std::cout << std::endl;

	delete[] array;
	delete[] new_array;
}

int main()
{	
	recursionArray();
}

