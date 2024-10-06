// Zadacha 1

#include <iostream>
using namespace std;

int input() {
	int N;

	do {
		cout << "N=";
		cin >> N;
	} while (N < 1);

	return N;
}

// Allocates matrix
int** matrix_alloc(int N) {
	int** matrix = new(nothrow) int* [N];
	if (!matrix)
		return nullptr;

	for (int i = 0; i < N; ++i) {
		matrix[i] = new(nothrow) int[N];		// Write the delete[]
	}

	return matrix;
}

void input_matrix(int** matrix, int N) {
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> matrix[i][j];
	return;
}

void compare_RC(int** matrix, int N, int col) {		// 'col' is the current column to which every row is compared
	int* row = new(nothrow) int[N];
	if (!row) {
		delete[] row;
		return;
	}

	// Main loop to go through every row
	for (int row_n = 0; row_n < N; ++row_n) {
		
		// Writing memory the n-th row
		for (int i = 0; i < N; ++i)
			row[i] = matrix[row_n][i];

		// Compare every element of 'row' to every element of the current column
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (row[j] == matrix[i][col]) {
					row[j] = 0;
					break;
				}
			}
		}

		bool perm = true;

		for (int i = 0; i < N; ++i) {
			if (row[i] != 0) {
				perm = false;
				break;
			}
		}

		if (perm) {
			cout << row_n << " " << col << "\n";
		}
	}

	delete[] row;
}

void permutations(int** matrix, int N) {
	
	for (int i = 0; i < N; ++i)
		compare_RC(matrix, N, i);

}

int main()
{
	int N = input();
	int** matrix = matrix_alloc(N);
	if (!matrix)
		return 1;

	input_matrix(matrix, N);
	permutations(matrix, N);
	return 0;
}