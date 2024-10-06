/*
 Introduction to Programming 2019 @ FMI
 Sample code for lecture #6

 Demonstrates simple tasks for arrays

***************
 Read an array and print it in reverse order
***************
*/

#include <iostream>
using namespace std;

// The minimal element in array
int minimum(int array[], int size)
{
    int min = array[0];
    for (int i = 1; i < size; ++i) {
        if (min > array[i]) {
            min = array[i];
        }
    }
    return min;
}

// The index of the smallest even element
int minEvenIndex(int array[], unsigned size)
{
    int min = -1;
    unsigned i;

    for (i = 0; i < size; ++i) {
        if (array[i] % 2 == 0) {
            min = i;
            break;
        }
    }

    for (; i < size; ++i) {
        if (array[min] > array[i] && array[i] % 2 == 0) {
            min = i;
        }
    }
    return min;
}


// The average of all elements in an array
double avg(int array[], int size)
{
    double sum = 0;
    
    // Avoid division by zero!
    if (!size) return sum;

    for (int i = 0; i < size; ++i)
        sum += array[i];

    return sum / size;
    
}

// Prints the array in reverse order
void print(int arr[], int n)
{
    //Note the type (int). It is important
    for (int i = n-1; i >= 0; --i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    const int MAX_SIZE = 200;

    unsigned n;
    int array[MAX_SIZE];

    do
    {
        cout << "N= ";
        cin >> n;
    }while (n == 0 || n > MAX_SIZE);

    for (unsigned i = 0; i < n; ++i) {
        cout << "a[" << i << "]=";
        cin >> array[i];
    }


    print(array, n);

    int min = minimum(array, n);
    cout << min << endl;

    int minEvIndex = minEvenIndex(array, n);
    if (minEvIndex < 0) {
        cout << "No even nums!\n";
    }
    else {
        array[minEvIndex] *= 2;
        print(array, n);
    }

    return 0;
}
