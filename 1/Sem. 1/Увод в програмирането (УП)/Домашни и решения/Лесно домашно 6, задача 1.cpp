// Lesno domashno 6, zadacha 1
// Comparing the products of the numbers in every row and column

#include <iostream>

const unsigned MAX = 100;

// Input for row of the matrix
unsigned inputRow() {
	unsigned row;
	do {
		std::cout << "Row = ";
		std::cin >> row;
	} while (row > MAX || row == 0);
	return row;	
}

// Input for column of the matrix
unsigned inputColumn() {
	unsigned column;
	do {
		std::cout << "Column = ";
		std::cin >> column;
	} while (column > MAX || column == 0);
	return column;
}

int main()
{
	int matrix[MAX][MAX];
	unsigned row = inputRow();
	unsigned column = inputColumn();

	// Inputs the matrix and calculates the product of the numbers in each row
	int rowProducts[MAX];	// Array for the products of the numbers in the rows 
	for (unsigned R = 0; R < row; ++R) {
		int a = 1;
		for (unsigned C = 0; C < column; ++C) {
			std::cin >> matrix[R][C];
			a *= matrix[R][C];
		}
		rowProducts[R] = a;
	}

	// Compares the product of the numbers in every row and column
	// and outputs the pairs 'row, column' with equal products
	for (unsigned C = 0; C < column; ++C) {
		
		int a = 1;		// The product of the numbers in a particular column

		for (unsigned R = 0; R < row; ++R) {
			a *= matrix[R][C];
		}

		for (unsigned R = 0; R < row; ++R) {
			if (rowProducts[R] == a) {
				std::cout << R << ", " << C << "\n";
			}
		}
	}
	
	return 0;
}