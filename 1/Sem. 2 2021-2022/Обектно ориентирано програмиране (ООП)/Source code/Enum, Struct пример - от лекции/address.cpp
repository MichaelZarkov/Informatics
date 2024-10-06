/*
 Object-Oriented Programming 2022 @ FMI
 Sample code for lecture #01

 Implementation of methods for simple Address structure
*/


#include <iostream>
#include "address.h"

using std::cin;
using std::cout;
using std::endl;

unsigned readNum(const char* text)
{
    unsigned num;

    cout << text ;
    cin >> num;
    
    while (!cin) 
    {
        cin.clear();
        cin.ignore();
    
        cout << "You must enter positive number! \n " << text << " again";
        cin >> num;
    }
    
    return num;
}

void readAddress(Address& address)
{
    cout << "Enter city: ";
    cin.getline(address.city, 32);

    cin.clear();
    
    cout << "Enter street: ";
    cin.getline(address.street, 64);

    // the input stream state is unknown, but it will be fixed, if needed
    address.number = readNum("Enter street number ");

    // leave the stream cleared and in good state
    clearCin();
}

void printAddress(const Address& addr)
{
    cout << "City: " << addr.city << endl;
    cout << "Street and number: " << addr.street << ", " << addr.number << endl;
}

void clearCin()
{
    cin.clear();
    while (cin && cin.rdbuf()->in_avail() && isspace(cin.peek()))
        cin.ignore();
    cin.clear();
}

