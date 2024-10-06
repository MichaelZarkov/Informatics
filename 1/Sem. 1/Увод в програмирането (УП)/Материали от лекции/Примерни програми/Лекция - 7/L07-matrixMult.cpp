/*
 Introduction to Programming 2019 @ FMI
 Sample code for lecture #7

 Demonstrates simple tasks for 2D arrays

***************
 Multiply two matrices
***************
*/

#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

unsigned readSize()
{
    unsigned n;
    do {
        cout << "N= ";
        cin >> n;
    } while (n == 0 || n > MAX_SIZE);
    return n;
}

void read2DArray(int array[][MAX_SIZE], unsigned n, unsigned m)
{
    for (unsigned i = 0; i < n; ++i) {
        for (unsigned j = 0; j < m; ++j) {
            cin >> array[i][j];
        }
    }
}

void print2DArray(int array[][MAX_SIZE], unsigned n, unsigned m)
{
    for (unsigned i = 0; i < n; ++i) {
        for (unsigned j = 0; j < m; ++j) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

/*
Multiplies the matrix m1 with dimension NxM by the matrix m2 with dimension MxK.
The result is in the matrix result, with dimension NxK
*/
void multMatrix(int m1[][MAX_SIZE], int m2[][MAX_SIZE],
				int result[][MAX_SIZE],
				unsigned n, unsigned m, unsigned k)
{
	for (unsigned i = 0; i < n; ++i) {
		for (unsigned j = 0; j < k; ++j) {
			result[i][j] = 0;
			for (unsigned internal = 0; internal < m; ++internal) {
				result[i][j] += m1[i][internal] * m2[internal][j];
			}
		}
	}
}

int main()
{
	int a[MAX_SIZE][MAX_SIZE],
		b[MAX_SIZE][MAX_SIZE],
		c[MAX_SIZE][MAX_SIZE];

	unsigned n = readSize(),
			 m = readSize(),
			 k = readSize();

	read2DArray(a, n, m);
	read2DArray(b, m, k);
	multMatrix(a, b, c, n, m, k);

	cout << '\n';
	print2DArray(a, n, m);
	cout << " multiplied by \n";
	print2DArray(b, m, k);
	cout << " equals \n";
	print2DArray(c, n, k);

	return 0;
}
