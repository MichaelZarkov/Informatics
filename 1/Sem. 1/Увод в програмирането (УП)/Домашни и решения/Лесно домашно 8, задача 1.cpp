// Lesno domashno 8, zadacha 1

#include <iostream>

// Validates input for rows and columns
size_t input() {
	size_t n;
	do
	{
		std::cin >> n;
		if (n < 1)
			std::cout << "Invalid number, try again.\n";
	} while (n < 1);
	return n;
}

void delete_matrix(int** matrix, size_t rows)
{
	for (size_t i = 0; i < rows; ++i)
		delete[] matrix[i];
	delete[] matrix;
}

// Allocates memory for the matrix
int** allocate_matrix(size_t rows, size_t columns) {
	int** matrix = new(std::nothrow) int* [rows];
	
	if (!matrix) return matrix;

	for (size_t i = 0; i < rows; ++i) {
		matrix[i] = new(std::nothrow) int[columns];
		if (!matrix[i]) {
			delete_matrix(matrix, i);
			delete[] matrix;
			return nullptr;
		}
	}

	return matrix;
}

// Inputs the values of the matrix
void input_matrix(int** matrix, size_t rows, size_t columns)
{
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < columns; ++j)
			std::cin >> matrix[i][j];
	}
}

// Finds the row with the smallest sum in a range and swaps it to the first position in that range
void min_sum(int** matrix, size_t from, size_t to, size_t columns) {
	size_t min = from;							// Number of the row with the smallest sum
	int smallest_sum = 0;						// Value of the smallest sum

	for (size_t i = 0; i < columns; ++i)		// Sets the first sum in the interval as the smallest
		smallest_sum += matrix[from][i];

	for (size_t i = from + 1; i < to; ++i) {
		int current_sum = 0;
		for (size_t j = 0; j < columns; ++j)
			current_sum += matrix[i][j];

		if (smallest_sum > current_sum) {
			smallest_sum = current_sum;
			min = i;
		}
	}

	// Swaps 2 rows
	int* p = matrix[from];
	matrix[from] = matrix[min];
	matrix[min] = p;
}

// Sorts the matrix in ascending order by the sum of its rows
void sort_matrix(int** matrix, size_t rows, size_t columns) {
	for (size_t i = 0; i < rows - 1; ++i) {
		min_sum(matrix, i, rows, columns);
	}
}

// Prints the hole matrix
void print_matrix(int** matrix, size_t rows, size_t columns)
{
	std::cout << std::endl << "Matrix:\n";

	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < columns; ++j) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << "\n";
	}
}



int main()
{
	std::cout << "Rows = ";
	size_t rows = input();
	std::cout << "Columns = ";
	size_t columns = input();

	int** matrix = allocate_matrix(rows, columns);
	if (!matrix)
		return 1;

	input_matrix(matrix, rows, columns);
	sort_matrix(matrix, rows, columns);
	print_matrix(matrix, rows, columns);
}