
#include <iostream>

bool isPrime(unsigned num1, unsigned num2)
{
	
	// Check only odd divisors
	for (int div = 3; div * div <= num1; div += 2) {
		if (num1 % div == 0) {
			return false;
		}
	}
	
	for (int div = 3; div * div <= num2; div += 2) {
		if (num2 % div == 0) {
			return false;
		}
	}

	return true;
}

int main()
{
	unsigned n;
	std::cout << "N=";
	std::cin >> n;

	if(n % 2 != 0) {
		std::cout << "Number must be even!";
		return 1;
	}

	unsigned num1 = 3;
	unsigned num2 = n - 3;
	n /= 2;

	while (num1 <= n) {
		if (isPrime(num1, num2)) {
			std::cout << "(" << num1 << ", " << num2 << ") ";
		}
		num1 += 2;
		num2 -= 2;
	}
}

