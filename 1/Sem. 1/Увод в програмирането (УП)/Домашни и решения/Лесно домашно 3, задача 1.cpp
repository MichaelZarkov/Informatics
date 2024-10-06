/*Lesno domashno 3, zadacha 1.

---------------

  Generates the sequence of numbers (in ascending order) with only prime divisors 2, 3 and 5.
  The next term Ti: Ti > T(i-1) and Ti is the smallest number that is the product of one of 
  the previous terms multiplied by 2, 3 or 5.

---------------

 */
#include <iostream>
#include <cmath>

int main()
{
	unsigned n;		// Length of the sequence
	std::cin >> n;		

	unsigned*b;
	b = new unsigned[n + 1];		// Sequence array
	b[0] = 1; 
	unsigned place = 1;		// Were in the sequence to write the next term
	unsigned n2 = 0, n3 = 0, n5 = 0;		// Which is the current term from the sequence that has to be multiplied by 2, 3 and 5

	for (unsigned i = 0; i < n;) {		// Loop for the length of the sequence
		
		unsigned t2 = 2 * b[n2];

		unsigned t3 = 3 * b[n3];

		unsigned t5 = 5 * b[n5];

		if (t2 < t3 && t2 < t5) {		// 2
			if (t2 != b[place - 1]) {		// Test if the current term is equal to the previous
				b[place] = t2;
				
				std::cout << b[place] << ", ";
				++place; ++i;
			}
			++n2;
		}
		else {
			if (t3 < t5) {		// 3
				if (t3 != b[place - 1]) {		// Test if the current term is equal to the previous
					b[place] = t3;

					std::cout << b[place] << ", ";
					++place; ++i;
				}
				++n3;
			}
			else {		// 5
				if (t5 != b[place] - 1) {		// Test if the current term is equal to the previous
					b[place] = t5;

					std::cout << b[place] << ", ";
					++place; ++i;
				}
				++n5;
			}
		}
		
	}
}

