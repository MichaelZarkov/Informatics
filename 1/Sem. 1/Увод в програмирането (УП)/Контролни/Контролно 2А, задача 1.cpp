// Kontrolno 2A, zadacha 1

#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::nothrow;

// Input for the number of rows
int inputRows() {
	int row;

	do {
		cout << "Rows=";
		cin >> row;
		if (row < 1)
			cout << "Rows must be bigger than 0. Try again.\n";
	} while (row < 1);

	return row;
}

// Input for the number of columns
int inputCol() {
	int col;

	do {
		cout << "Col=";
		cin >> col;
		if (col < 1)
			cout << "Columns must be bigger than 0. Try again.\n";
	} while (col < 1);

	return col;
}

// Reads matrix from console
void inputMatrix(unsigned** matrix, int rows, int cols) {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j)
			cin >> matrix[i][j];
	}
}

// Deletes matrix to a certain row
void deleteMatrix(unsigned** matrix, int row) {
	
	for (int i = 0; i < row; i++)
		delete[] matrix[i];
	delete[] matrix;
}

// Allocates matrix by rows
unsigned** allocMatrix(int row, int col) {
	
	unsigned** matrix = new(nothrow) unsigned*[row];
	if (!matrix)
		return matrix;

	for (int i = 0; i < row; ++i) {
		matrix[i] = new(nothrow) unsigned[col];
		if (!matrix[i]) {
			deleteMatrix(matrix, i);
			delete[] matrix;
			return nullptr;
		}
	}

	return matrix;
}

// Outputs to the console which pairs of columns are permutations
void colPermutations(unsigned** matrix, int rows, int cols) {
	/* Same algorithum but with "int" array

	   ------------------------------------

	int* column = new(nothrow) int[rows];		// Current column which is compared to the others
	if (!column)								// I SHOULD TRY DOING THIS WITH A BOOL ARRAY			
		return;
	
	   ------------------------------------
	*/

	bool* column = new(nothrow) bool[rows];
	if (!column)
		return;

	for (int i = 0; i < cols; ++i) {
		for (int j = i + 1; j < cols; ++j) {
			/* Same algorithum but with "int" array
			
			   ------------------------------------

			for (int a = 0; a < rows; ++a)		// Writes the 'i-th' column to 'column[]'
				column[a] = matrix[a][i];
			
			// Lop for determining if permutation
			for (int a = 0; a < rows; ++a) {
				for (int b = 0; b < rows; ++b) {
					if (column[b] == matrix[a][j]) {
						column[b] = -1;
						break;
					}
				}
			}

			bool perm = true;					// True if the columns are permutations
			for (int a = 0; a < rows; ++a) {
				if (column[a] != -1) {
					perm = false;
					break;
				}
			}

			if (perm) {
				cout << i << " " << j << "\n";

			   -------------------------------------
			}*/
			
			for (int a = 0; a < rows; ++a)
				column[a] = true;				// True represents unmatched place

			for (int a = 0; a < rows; ++a) {
				for (int b = 0; b < rows; ++b) {
					if (matrix[a][i] == matrix[b][j] && column[b]) {
						column[b] = false;
						break;
					}
				}
			}

			for (int a = 0; a < rows; ++a) {
				if (column[a]) {
					column[0] = true;
					break;
				}
			}

			if (!column[0]) {
				cout << i << " " << j << "\n";
			}
		}
	}

	delete[] column;
}

int main()
{	
	int row = inputRows();
	int col = inputCol();

	unsigned** matrix = allocMatrix(row, col);
	inputMatrix(matrix, row, col);
	colPermutations(matrix, row, col);
}