/*Domashno 1; zadacha 2*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	cout << "Input a 9 digit card number:\n";
	
	unsigned int inp;
	cin >> inp;
	   
	int n1 = inp / 100000000;		// Card version
	int n2 = inp / 10000000 % 10;		// Not used number - set to 0 (because card number has to be unique)
	int n9 = inp % 10;					// Not used number - set to 0 (because card number has to be unique)
	int id = (inp / 10) % 100000;	// Card id
	
	// Test for the validity of the card number
	if ((n1 == 0) || (id == 0))
	{
		cout << "Invalid card number" << endl;
		return 1;
	}

	if ((n2 != 0) || (n9 != 0))
	{
		cout << "Invalid card number" << endl;
		return 1;
	}

	// Test for the specialty
	int n3 = inp / 1000000 % 10;		// Number of the specialty
	string specialty;
	switch (n3)
	{
	case 0:
		specialty = "Informatics";
		break;
	case 1:
		specialty = "Computer Science";
		break;
	case 2:
		specialty = "IT Sistems";
		break;
	case 3:
		specialty = "Software Engeneering";
		break;
	case 4:
		specialty = "Aplied Mathematics";
		break;
	case 5:
		specialty = "Mathematics";
		break;
	case 6:
		specialty = "Statistics";
		break;
	case 8:
		specialty = "Mathematics and Informatics";
		break;
	default:
		cout << "Invalid card number" << endl;
		return 1;
	}

	cout << "{\"card_number\": " << n1 << ", \"owner_spec\": \"" << specialty << "\", \"owner_id\": " << id << "}\n";
		 
	return 0;
}
