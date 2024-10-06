// Lesno domashno 7, zadacha 1

#include <iostream>
#include <cstdlib>
#include <ctime>


// Returns a number between 0 and 9223372036854775807
unsigned long long random_number_generator() {
	/* 
	   A random number between 0 and 2^63 - 1 is a random sequence of 63 one's and zero's in a row.
	   The function 'rand()' gives a number between 0 and 2^15 - 1.
	   This means 'rand()' gives a random sequence of 15 one's and zero's.
	   This function calls 'rand()', takes the 15 random bits and shifts them to the correct place (this happens 5 times)
	   to give us a string of 63 random bits which are used as a single number (in the range [0, 2^63 - 1]).
	*/
	unsigned long long a = 0;

	for (int i = 0; i < 5; ++i) {
		unsigned long long b = rand();
		if (i == 4) {
			b %= 8;	
		}
		else {
			b <<= 48 - (15 * i);		// Shifting the bits
		}
		a += b;
	}
	return a;
}


void random_algorithm(unsigned long long a) {
	unsigned long long low = 0, high = 9223372036854775807;		// Range in which 'a' is
	unsigned long long b = random_number_generator();
	unsigned count = 0;											// Counter for number of guesses

	do {
		++count;
		if (b > a) {
			high = b;
			b = (random_number_generator() % (high - low)) + low;
		}
		else if (b < a) {
			low = b;
			b = (random_number_generator() % (high - low) + low);
		}
		else {
			std::cout << "\nResulting number from random search: " << b << "\nNumber of guesses: " << count;
			return;
		}
	} while (true);
	return;
}


// Guesses the number with binary search
void standart_algorithm(unsigned long long a) {
	unsigned long long mid = 4611686018427387904;		// 2^63 / 2
	unsigned long long incr = 2305843009213693952;		// 2^63 / 4
	unsigned count = 0;									// Counter for number of guesses

	do {
		++count;
		if (mid > a) {
			mid -= incr;
			if (incr > 1) {		// If 'a' cannot be 0, use  'incr /= 2;'  instead of  'if (incr > 1) { incr /= 2; }' (remove the 'if')
				incr /= 2;
			}
		}
		else if (mid < a) {
			mid += incr;
			if (incr > 1) {		// If 'a' cannot be 0, use  'incr /= 2;'  instead of  'if (incr > 1) { incr /= 2; }' (remove the 'if')
				incr /= 2;
			}
		}
		else {
			std::cout << "Resulting number from binary search: " << mid << "\nNumber of guesses: " << count;
			return;
		}
	} while (true);
	
	return;
}


int main()
{
	//9223372036854775807 = 2^63 - 1
	
	srand(time(0));

	unsigned long long a = random_number_generator();

	std::cout << "The random number is: " << a << "\n\n";

	standart_algorithm(a);
	random_algorithm(a);
	
	return 0;
}