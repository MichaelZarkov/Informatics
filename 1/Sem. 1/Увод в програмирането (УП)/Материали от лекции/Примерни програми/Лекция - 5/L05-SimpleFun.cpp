/*
 Introduction to Programming 2019 @ FMI
 Sample code for lecture #5

 Demonstrates sample functions

***************
 Minimum of two numbers
***************
*/
#include <iostream>
using namespace std;

int min(int x, int y)
{
    if (x < y) {
        y = 0;
        return x;
    }
    else {
        x = 0;
        return y;
    }
}

void swap(int& x, int& y)
{
    cout << "swap: " << x << " " << y << endl;
    int help = x;
    x = y;
    y = help;
    cout << "swap: " << x << " " << y << endl;
}

int main()
{
    int a, b;
    cin >> a >> b;

    cout << min(a, b+3) << endl;
    cout << "main: " << a << " " << b << endl;

    swap(a, b);
    cout << "main: " << a << " " << b << endl;
    return 0;
}
