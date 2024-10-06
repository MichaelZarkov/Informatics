/*
 Introduction to Programming 2019 @ FMI
 Sample code for lecture #5

 Demonstrates sample functions

***************
  Reads N numbers and find their sum.
  Also find the average
***************
*/

#include <iostream>
using namespace std;

unsigned inputN(unsigned max)
{
    unsigned n;
    do {
        cout << "N= ";
        cin >> n;
    } while (n >= max);

    return n;
}

unsigned sumNumbers (unsigned n)
{
    unsigned sum = 0;
    n = inputN(MAX);
    for (unsigned i = 0; i < n; ++i) {
        cout << "Number " << i << " = ";
        unsigned x;
        cin >> x;
        sum += x;
    }

    return sum;
}

int main()
{
    const unsigned MAX = 100;

    unsigned n = inputN(MAX);
    unsigned sum = sumNumbers(n);

    cout << "Sum: " << sum << "\n"
         << "Avg: " << (float)sum / n << endl;

    return 0;
}
