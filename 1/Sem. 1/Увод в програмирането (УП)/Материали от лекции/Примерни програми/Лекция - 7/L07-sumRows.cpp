/*
 Introduction to Programming 2019 @ FMI
 Sample code for lecture #7

 Demonstrates simple tasks for 2D arrays

***************
 Input a 2D array and finds the sum of elements by row and column
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

int sumArray(int arr[], unsigned n)
{
    int sum = 0;
    for (unsigned i = 0; i < n; ++i)
        sum += arr[i];
    return sum;
}

int sumRow(int array[][MAX_SIZE], unsigned row, unsigned size)
{
//    int sum = 0;
//    for (unsigned i = 0; i < size; ++i)
//        sum += array[row][i];
//    return sum;
    return sumArray(array[row], size);
}

int sumCol(int array[][MAX_SIZE], unsigned col, unsigned size)
{
    int sum = 0;
    for (unsigned i = 0; i < size; ++i)
        sum += array[i][col];
    return sum;
}

int main()
{
    unsigned n, m;
    int matrix[MAX_SIZE][MAX_SIZE];

    n = readSize();
    m = readSize();
    read2DArray(matrix, n, m);

    cout << endl;
    print2DArray(matrix, n, m);

    for (unsigned i = 0; i < m; ++i) {
        cout << sumCol(matrix, i, n) << "  ";
    }

    cout << endl;
    return 0;
}
