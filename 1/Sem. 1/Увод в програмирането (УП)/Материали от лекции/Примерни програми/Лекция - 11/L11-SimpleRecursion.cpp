/*
 Introduction to Programming 2019 @ FMI
 Sample tasks for lecture #11

Basic Recursive functions

***************
 Factorial, Fibonacci, power
 Sum of the elements in array
 Binary search, and string match
***************
*/


#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


// A traditional factorial function.
// Basic example of direct, linear recursion
unsigned long long fact(unsigned n)
{
    if (n == 0)
        return 1;
    else
        return n*fact(n-1);
}


// Fibonacci numbers
// Basic example of direct, multiple recursion.
unsigned long long fib(unsigned n)
{
    if (n < 2)
        return 1;
    else
        return fib(n-1) + fib(n-2);
}


// Fibonacci numbers
// Optimized version - tail and linear recursion
unsigned long long fib2(unsigned n, unsigned long long f1, unsigned long long f2)
{
    if (n == 0)
        return f1;
    else
        return fib2(n-1, f1+f2, f1);
}


// Wrapper of the recursive function
// The idea is to hide the additional parameters
unsigned long long fibWrap(unsigned n)
{
    return fib2(n, 1, 0);
}


// Calculate X powered N
// Classical linear recursive algorithm
double power(double x, unsigned n)
{
    if (n == 0)
        return 1;
    return x * power(x, n-1);
}


// Three different functions to calculate the sum of an array
int sumR(int * arr, unsigned n)
{
    if (n == 0)
        return 0;
    return arr[n-1] + sumR(arr, n-1);
}

int sumL(int * arr, unsigned n)
{
    if (n == 0)
        return 0;
    return *arr + sumL(arr+1, n-1);
}

int sumAcc(int * arr, unsigned n, int res = 0)
{
    if (!n) return res;
    return sumAcc(arr+1, n-1, res + *arr);
}

void print(int * arr, int n)
{
    if (n != 0)
    {
        cout << *arr << " ";
        print(arr+1, n-1);
    }
}

void print(const char* str)
{
    if (*str) {
        cout <<*str;
        print(str+1);
    } else {
        cout << "\n";
    }
}

// Binary search algorithm with recursion.
// Uses wrapper to clear the usage.
// TODO: Make that function using pointers and no additional argument
int binSearchRec(int* arr, unsigned l, unsigned r, int x)
{
    if (l >= r) return -1;
    int m = (l+r)/2;

    if (arr[m] == x)
        return m;
    if (arr[m] < x)
        return binSearchRec(arr, m+1, r, x);
    return binSearchRec(arr, l, m, x);
}

//The wrapper
int binarySearch(int* arr, unsigned n, int x)
{
    return binSearchRec(arr, 0, n, x);
}


// Check if a string is prefix of another string with recursion
bool prefix(const char* str1, const char* str2)
{
    if (!*str2) return true;
    if (!*str1) return false;
    return *str1 == *str2 && prefix(str1+1, str2+1);
}


// Check if a string is part of a string with recursion
const char* strstr(const char* where, const char* what)
{
    if (!*where)
        return nullptr;
    if (prefix(where, what))
        return where;
    return strstr(where+1, what);
}


// Prints a number triangle, using only recursion
void printRowRec(int n, int pos)
{
    if (n == pos)
    {
        cout << n << " ";
    }
    else
    {
        cout << pos << " ";
        printRowRec(n, pos+1);
        cout << pos << " ";
    }
}

void printRow(int row, int n)
{
    if (row < n)
    {
        cout << "  ";
        printRow(row, n-1);
    }
    else
    {
        printRowRec(row, 1);
        cout << "\n";
    }
}

void triangleRec(int n, int row)
{
    if (row <= n)
    {
        printRow(row, n);
        cout << "\n";
        triangleRec(n, row+1);
    }
}

/* ������� ����������
      1
    1 2 1
  1 2 3 2 1
    .....
1 ... n ... 1
*/
void triangle(int n)
{
    triangleRec(n, 1);
}


int main()
{
/*    for (int n = 1; n < 45; ++n)
        cout << fib(n) << " " << fibWrap(n) << endl;
*/
/*
    for (int n = 1; n <= 10; ++n)
        cout << power(2, n) << endl;
*/

    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//    cout << sumL(arr, 10) << endl;
//    cout << sumR(arr, 10) << endl;
//    cout << sumAcc(arr, 10) << endl;
    print(arr, 10);
//    cout << endl;
//    cout << binarySearch(arr, 10, 3) << endl;
//    cout << binarySearch(arr, 10, 0) << endl;


//    triangle(5);












    srand(time(0));
    void Tannenbaum(int n);
    Tannenbaum(5);

    return 0;
}


/* **************************
 * A Christmas joke ;)
 * A recursive Tannenbaum
 * **************************/

void printRowRec(int n, int pos, char what)
{
    if (n == pos)
    {
        cout << what;
    }
    else
    {
        cout << ((what != '*' || rand()%6) ? what : 'o');
        printRowRec(n, pos+1, what);
        cout << ((what != '*' || rand()%6) ? what : 'o');
    }
}

void printTannenbaumRow(int row, int n)
{
    if (row < n)
    {
        cout << " ";
        printTannenbaumRow(row, n-1);
    }
    else
    {
        printRowRec(row, 1, row>1?'*':'+');
        cout << "\n";
    }
}

void TannenbaumRec(int n, int row)
{
    if (row <= n)
    {
        printTannenbaumRow(row, n);
        cout << "\n";
        TannenbaumRec(n, row+1);
    }
}

void Tannenbaum(int n)
{
    n = 2*n;
    TannenbaumRec(n, 1);

    printRowRec(n/2, 1, ' ');
    printRowRec(1, 1, '|');
    cout << "\n";
}


//-Wl,--stack -Wl,4096 -std=c++11
