#include <iostream>
#include <cmath>

int main()
{
	unsigned n;
	std::cin >> n;

	unsigned test_num = 1;

	for (unsigned i = 0; i < n;) {
		unsigned num = test_num;

		while (num % 2 == 0) {
			num /= 2;
			if (num == 1) {
				std::cout << test_num << ", ";
				++i;
			}
		}

		while (num % 3 == 0) {
			num /= 3;
			if (num == 1) {
				std::cout << test_num << ", ";
				++i;
			}
		}

		while (num % 5 == 0) {
			num /= 5;
			if (num == 1) {
				std::cout << test_num << ", ";
				++i;
			}
		}
		++test_num;
	}

	
}