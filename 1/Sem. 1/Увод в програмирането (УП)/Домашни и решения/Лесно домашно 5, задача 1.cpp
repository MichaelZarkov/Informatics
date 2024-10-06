// Lesno domashno 5, zadacha 1

#include <iostream>

int main()
{
	const int N = 1000;
	double coef[N];		// Array for the coefficients
	int pow;			// Power of the polinomial
	int der;			// Order of derivative

	std::cout << "Power: ";
	std::cin >> pow;
	
	std::cout << "Coefficients: ";
	for (int i = 0; i <= pow; ++i) {
		std::cin >> coef[i];
	}
	
	std::cout << "Derivative: ";
	std::cin >> der;

	if (pow == 0) {
		std::cout << 0;
		return 0;
	}

	double a = pow * 1.0;			// Replaces 'i' because it has to be floating point
	for (int i = 0; i < der; ++i) {
		a = pow - i;
		for (int i = 0; i <= pow; ++i) {
			coef[i] *= a;
			a -= 1.0;
		}
	}

	int p = pow;
	for (int i = 0; i <= p - der; ++i) {
		if (coef[i] != 0) {
			std::cout << coef[i];
			if (pow - der > 1) {
				std::cout << "*X^" << pow - der;
			}
			else if (pow - der == 1) {
				std::cout << "*X";
			}

			if (pow - der > 0) {
				std::cout << " + ";
			}
			--pow;
		}
	}
	return 0;
}