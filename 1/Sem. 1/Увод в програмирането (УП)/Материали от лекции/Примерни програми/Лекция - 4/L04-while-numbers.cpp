/*
 Introduction to Programming 2019 @ FMI
 Sample task for lecture #4

 Demonstrates while statement

***************
 Calculates the sum of entered numbers
***************
*/
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int sum = 0;
    unsigned n;          // total count of numbers

    cout << "How many numbers will be entered? ";
    cin >> n;

    unsigned numberIndex = 1;

    while (numberIndex <= n) {
        int number;
        cout << "Number " << numberIndex << " = ";
        cin >> number;
        sum += number;
        ++numberIndex;
    }

    cout << "Sum = " << sum << endl;
    return 0;
}
