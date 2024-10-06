/*
 Introduction to Programming 2019 @ FMI
 Sample code for lecture #5

 Demonstrates for statement

***************
 Print a number triangle
***************
*/
#include <iostream>

using namespace std;

int main()
{
    int n;
    const int width = 3;
    cout << "n= ";
    cin >> n;

    for (int row = 1; row <= n; ++row) {
        //Prints one row of the triangle - it is built from several components:

        //Leading spaces
        for (int i = 0; i < n - row; ++i) {
            for (int j = 0; j < width; ++j) cout << ' ';
        }

        //Increasing sequence
        for (int num = 1; num < row; ++num) {
            cout.width(width);
            cout << num;
        }

        //Decreasing sequence
        for (int num = row; num > 0; --num) {
            cout.width(width);
            cout << num;
        }
        cout << endl;
    }
    return 0;
}
