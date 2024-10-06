/*
 Introduction to Programming 2019 @ FMI
 Sample tasks for lecture #12

  Main function with arguments
*/

#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;
using std::cin;

int main(int argc, const char* argv[])
{
    cout << argc << endl;

    for (int i = 0; i < argc; ++i)
        cout << argv[i] << endl;
    int x;
    cin >> x;
    cout << x << endl;
    std::cerr << "ERRor " << endl;
    return 0;
}
