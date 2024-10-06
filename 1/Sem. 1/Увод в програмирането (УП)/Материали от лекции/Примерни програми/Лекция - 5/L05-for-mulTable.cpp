/*
 Introduction to Programming 2019 @ FMI
 Sample code for lecture #5

 Demonstrates for statement

***************
 Print the multiplication table
***************
*/
#include <iostream>

using namespace std;

int main()
{
    //Table header
    cout << "*| ";
    for (int i = 1; i < 10; ++i) {
        cout << "\t" << i;
    }
    cout << endl;

    //Separator line
    cout << "--";
    for (int i = 1; i < 10; ++i) {
        cout << "--------";
    }
    cout << endl;

    //And the table row by row
    for (int a = 1; a < 10; ++a) {
        cout << a << "| ";
        for (int b = 1; b < 10; ++b) {
            cout << "\t" << a*b;
        }
        cout << endl;
    }
    return 0;
}
