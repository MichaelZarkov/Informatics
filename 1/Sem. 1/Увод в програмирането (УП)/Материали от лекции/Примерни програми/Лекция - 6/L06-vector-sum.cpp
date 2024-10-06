/*
 Introduction to Programming 2019 @ FMI
 Sample code for lecture #6

 Demonstrates simple tasks for arrays

***************
 Read two arrays and calculate their vector sum
***************
*/

#include <iostream>
using namespace std;

unsigned readSize(unsigned maxSize)
{
    unsigned n;
    do {
        cout << "N= ";
        cin >> n;
    } while (n == 0 || n > maxSize);
    return n;
}

void readArray(int array[], int size)
{
    for (unsigned i = 0; i < size; ++i) {
        cout << "a[" << i << "]=";
        cin >> array[i];
    }
}

// Prints an array. The size should be greater than 0!
void printArray(int array[], size_t size)
{
    cout << array[0];
    for (unsigned i = 1; i < size; ++i) {
        cout << ", " << array[i];
    }
    cout << endl;
}

/*
 * Calculates the vector sum of a1 and a2. 
 * The result is stored in the argument result
 * This function expects:
 *      the size of a1 to be equal of the size of a2
 *      the array result to be large enough to store the sum
 */
void vectorSum(int a1[], int a2[], int result[], int size)
{
    for (int i = 0; i < size; ++i) {
        result[i] = a1[i] + a2[i];
    }
}

int main()
{
    const int MAX_SIZE = 100;

    int a[MAX_SIZE], b[MAX_SIZE];
    unsigned n = readSize(MAX_SIZE);

    readArray(a, n);
    readArray(b, n);

    printArray(a, n);
    printArray(b, n);

    int c[MAX_SIZE];
    vectorSum(a, b, c, n);

    printArray(c, n);
    return 0;
}
