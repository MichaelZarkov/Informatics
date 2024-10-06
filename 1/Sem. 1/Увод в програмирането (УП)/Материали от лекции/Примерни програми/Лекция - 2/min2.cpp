/*
 Introduction to Programming 2019 @ FMI
 Sample task for lection #2

***************
 Read two integer numbers from the console
and print the smaller one
***************
*/

#include <iostream>
using namespace std;

int main()
{
    int num1, num2;
    cout << "Enter numbers: ";      // Подканващо съобщение
    cin >> num1 >> num2;

    {
        // Изход на резултата
        cout << "The smaller number is "
             << (num1 < num2 ? num1 : num2) << endl;
    }
    return 0;
}
