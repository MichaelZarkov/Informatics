/*
 Introduction to Programming 2019 @ FMI
 Sample tasks for lecture #12

  Function pointers.

***************
 Accumulate algorithm over array
 Map function on a string
 Simple interactive calculator
*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

typedef int (*binFun)(int, int);
int accumulate(int a[], int n, int start, binFun fun)
{
    for (int i = 0; i < n; ++i)
        start = fun(start, a[i]);
    return start;
}

/* **********************************************************/

typedef char (*funPtr)(char);

void processString(char* text, funPtr processor)
{
    while (*text) {
        *text = processor(*text);
        ++text;
    }
}

char toUpper(char c)
{
    if (c >= 'a' && c <= 'z')
        return c - 'a' + 'A';
    return c;
}

char toLower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c - 'A' + 'a';
    return c;
}

/* **********************************************************/



int sum(int a, int b)
{
    return a+b;
}

int sub(int a, int b)
{
    return a-b;
}

int mul(int a, int b)
{
    return a*b;
}

int Div(int a, int b)
{
    if (b) return a/b;
    return 0;
}

int mod(int a, int b)
{
    if (b) return a%b;
    return 0;
}

int eq(int a, int b)
{
    return a==b;
}

int gt (int a, int b)
{
    return a > b;
}

const char   oper[]      = {'+', '-', '*', '/', '%', '=', '>'};
const binFun functions[] = {sum, sub, mul, Div, mod,  eq, gt};
const int    arraySize   = sizeof(oper)/sizeof(oper[0]);

int calc(int a, int b, char operation)
{
    for (int i = 0; i < arraySize; ++i)
        if (oper[i] == operation)
            return functions[i](a, b);
    cout << "unknown operation!\n";
    return -1;
}



int main()
{
/*
    int arr[] = {1, 2, 3, 1, 5};
    cout << accumulate(arr, 5, 0, sum) << endl;
    cout << accumulate(arr, 5, 1, mul) << endl;
    cout << accumulate(arr, 5, arr[0], [](int a, int b){return a<b?a:b;}) << endl;
*/

/*
    while (rand()%5) {
        char text[] = "I like to point things. Even functions ;)";
        switch(rand()%3) {
            case 0:    processString(text, toUpper);
            break;
            case 1:    processString(text, toLower);
            break;
            case 2:    processString(text, [](char){return '0';});
            break;
        }
        cout << text << endl;
    }
*/

/*
    char c;
    do {
        int x, y;
        cin >> x >> c >> y;
        cout << calc (x, y, c) << "\n";
    } while (cin && c != 'e');
*/
    return 0;
}
