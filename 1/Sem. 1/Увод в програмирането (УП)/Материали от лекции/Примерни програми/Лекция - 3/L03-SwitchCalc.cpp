/*
 Introduction to Programming 2019 @ FMI
 Sample task for lecture #3

 Demonstrates switch statement

***************
 Sample integer calculator
***************
*/

#include <iostream>
using namespace std;

int main()
{
    int x, y;
    char operation; // one of +, -, * or /

    cout << "X = ";
    cin >> x;
    cout << "Y = ";
    cin >> y;

    cout << "Operation: ";
    cin >> operation;

    int result;
    switch(operation)
    {
    case '+':
        result = x+y;
        break;
    case '-':
        result = x-y;
        break;
    case '*':
        result = x*y;
        break;
    case '/':
        if (y != 0)
        {
            result = x/y;
        }
        else
        {
            cout << "Can not divide by 0!" << endl;
            return 1;
        }
        break;
    default:
        cout << "Unknown operation!" << endl;
        return 1;
    }

    cout << x << operation << y << '=' << result << endl;
    return 0;
}
