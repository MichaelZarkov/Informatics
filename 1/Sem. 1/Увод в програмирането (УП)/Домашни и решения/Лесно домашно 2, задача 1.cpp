
/*Lesno domashno 2, zadacha 1*/


#include <iostream>
#include <cmath>

int main()
{
	int a;
	std::cout << "Input: ";
	std::cin >> a;
	
		if ((a < 0) || (a > 3000))		// Check if the number is valid
		{
			std::cout << "Invalid number!";
			return 1;
		}


	unsigned thousands = a / 1000;		// Determine the number of the thousands in Roman numarls
	std::string R;		// Number 'a' in Roman numerals
		switch (thousands)
		{
		case 1:
			R = "M";
			break;
		case 2:
			R = "MM";
			break;
		case 3:
			R = "MMM";
		}

	unsigned hundreds = (a / 100) % 10;		// Determine the number of the hundreds in Roman numarls
		switch (hundreds)
		{
		case 1:
			R = R + "C";
			break;
		case 2:
			R = R + "CC";
			break;
		case 3:
			R = R + "CCC";
			break;
		case 4:
			R = R + "CD";
			break;
		case 5:
			R = R + "D";
			break;
		case 6:
			R = R + "DC";
			break;
		case 7:
			R = R + "DCC";
			break;
		case 8:
			R = R + "DCCC";
			break;
		case 9:
			R = R + "CM";
		}

	unsigned tens = (a / 10) % 10;		// Determine the number of the tens in Roman numarls
		switch (tens)
		{
		case 1:
			R = R + "X";
			break;
		case 2:
			R = R + "XX";
			break;
		case 3:
			R = R + "XXX";
			break;
		case 4:
			R = R + "XL";
			break;
		case 5:
			R = R + "L";
			break;
		case 6:
			R = R + "LX";
			break;
		case 7:
			R = R + "LXX";
			break;
		case 8:
			R = R + "LXXX";
			break;
		case 9:
			R = R + "XC";
		}

	unsigned ones = a % 10;		// Determine the number of the ones in Roman numarls
		switch (ones)
		{
		case 1:
			R = R + "I";
			break;
		case 2:
			R = R + "II";
			break;
		case 3:
			R = R + "III";
			break;
		case 4:
			R = R + "IV";
			break;
		case 5:
			R = R + "V";
			break;
		case 6:
			R = R + "VI";
			break;
		case 7:
			R = R + "VII";
			break;
		case 8:
			R = R + "VIII";
			break;
		case 9:
			R = R + "IX";
		}

	std::cout << "Output: " << R << std::endl;
	return 0;
}