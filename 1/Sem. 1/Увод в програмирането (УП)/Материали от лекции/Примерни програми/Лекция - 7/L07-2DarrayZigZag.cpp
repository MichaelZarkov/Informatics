/*
 Introduction to Programming 2019 @ FMI
 Sample code for lecture #7

 Demonstrates simple tasks for 2D arrays

***************
 Input a 2D array and prints it in a Zig-Zag way
***************
*/

#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

// Prints an array from left to right or in opposite direction
//depending on the value of ltr parameter
void printArray(int array[], int size, bool ltr = true);

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
        printArray(array[i], m);
    }
}

void printZigZag(int array[][MAX_SIZE], unsigned n, unsigned m)
{
    for (unsigned i = 0; i < n; ++i) {
        printArray(array[i], m, i%2 == 0);
    }
}

void printArray(int array[], int size, bool ltr)
{
    if (ltr) {
        for (unsigned i = 0; i < size; ++i) {
            cout << array[i] << " ";
        }
    }
    else {
        for (int i = size-1; i >= 0; --i) {
            cout << array[i] << " ";
        }
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

    print2DArray(matrix, n, m);
    cout << endl;

    printZigZag(matrix, n, m);
    cout << endl;

    return 0;
}
