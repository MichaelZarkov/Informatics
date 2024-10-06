// Lesno domashno 2, zadacha 2.

#include <iostream>
#include <cmath>
#include <bitset>

int main()
{
	unsigned id, num;		// 'id' - 9 digit card number; 'num' - the second digit of id
	std::cin >> id;
	num = (id / 10000000) % 10;

	if (num > 7)		// Test if 'num' is a valid base 8 number
	{
		std::cout << "Imitative.\n";
		return 0;
	}

	// Step 1 - finding the product of the sums of the digits in the odd and even positions in 'id'
	unsigned odd_sum = 0, even_sum = 0;
	unsigned devider = 1, odd_even = 1;
	
	while (devider != 1000000000)
	{
		unsigned N1 = (id / devider) % 10;
		devider = devider * 10;
		
		if (odd_even % 2 == 0)
		{
			even_sum = even_sum + N1;
		}
		else
		{
			odd_sum = odd_sum + N1;
		}
		
		++odd_even;

	}
	unsigned test_num = even_sum * odd_sum; // Resulting number
	// Step 1 ************
	
	

	// Step 2 - applying bitwise OR to 'test_num' 
	if (num < 2)
	{
		test_num = test_num | 0xbabe;
	}
	else
	{
		if (num > 5)
		{
			test_num = test_num | 0xcafe;
		}
		else
		{
			test_num = test_num | 0xc001;
		}
	}
	// Step 2 ************



	// Step 3 - applying bitwise XOR to 'test_num'
	if (num % 2 == 0)
	{
		test_num = test_num ^ 0xface;
	}
	else
	{
		test_num = test_num ^ 0xc0de;
	}
	// Step 3 ************



	// Step 4 - taking the four most significant bits of 'test_num'
	unsigned b = test_num;
	int i = 0;

	while (b != 0)
	{
		b = b >> 1;
		++i;
	}

	i = i - 4;
	while (i > 0)
	{
		test_num = test_num >> 1;
		--i;
	}
	

	if (test_num / 10 > 0)
	{
		test_num = test_num % 10;
	}
	// Step 4 ************


	
	if (test_num == (id % 10))		// Check if 'test_num' and the 'check digit' of id are equal
	{
		std::cout << "Authentic";
		return 0;
	}
	else
	{
		std::cout << "Imitative";
		return 1;
	}
}