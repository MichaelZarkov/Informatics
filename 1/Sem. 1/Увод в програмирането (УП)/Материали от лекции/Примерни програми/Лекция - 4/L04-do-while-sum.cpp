/*
 Introduction to Programming 2019 @ FMI
 Sample task for lecture #4

 Demonstrates do-while statement

***************
 Calculates the sum of entered numbers.
 End criteria is entering zero.
***************
*/
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int number, sum = 0;
    do {
        cout << "Number = ";
        cin >> number;
        sum += number;
    } while (number != 0);

    cout << "Sum = " << sum << endl;
    return 0;
}
