/*
 Introduction to Programming 2019 @ FMI
 Sample code for lecture #7

 Demonstrates simple tasks for 2D arrays

***************
 Prints a matrix by in a diagonal way
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

void printDiag(int array[][MAX_SIZE], int n, int m)
{
    for (int diag = -(m-1); diag < m; ++diag) {
        for (int row = 0; row < n; row++) {
            int col = diag + row;
            if (col >= 0 && col < m)
                cout << array[row][col] << " ";
        }
        cout << endl;
    }
}

void printArray(int array[], int size)
{
    for (unsigned i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    unsigned n, m;
    int matrix[MAX_SIZE][MAX_SIZE];

    n = readSize();
    m = readSize();
    read2DArray(matrix, n, m);

    cout << endl;
    for (int i = 0; i < n; ++i) {
        printArray(matrix[i], m);
    }
    cout << endl;

    printDiag(matrix, n, m);
    cout << endl;
    return 0;
}
