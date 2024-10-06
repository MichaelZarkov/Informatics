
//9. Finds sin

#include <iostream>
#include <cmath>

void sin(double x, int n) {
	double sin = 1.0;
	double p = 2;
	for (int i = 1; i <= n; ++i) {
		double factorial = 1;
		for (int i = 1; i <= p; ++i) {		// Calculates factorial
			factorial *= i;
		}
		if (i % 2 == 0) {
			sin += pow(x, p) / factorial;
		}
		else { 
			sin -= pow(x, p) / factorial;
		}
		p += 2;
	}
	sin = sqrt(1.0 - pow(sin, 2));		// Calculates sin
	std::cout << "Result: " << sin;
	return;
}


// Finds tg

void tg(double x, int n) {
	double cos = 1.0;
	double p = 2;
	for (int i = 1; i <= n; ++i) {
		double factorial = 1;
		for (int i = 1; i <= p; ++i) {		// Calculates factorial
			factorial *= i;
		}
		if (i % 2 == 0) {
			cos += pow(x, p) / factorial;
		}
		else {
			cos -= pow(x, p) / factorial;
		}
		p += 2;
	}
	cos = sqrt(1.0 - pow(cos, 2)) / cos;		// Calculates tg
	std::cout << "Result: " << cos;
	return;
}


// Finds cotg

void cotg(double x, int n) {
	double cos = 1.0;
	double p = 2;
	for (int i = 1; i <= n; ++i) {
		double factorial = 1;
		for (int i = 1; i <= p; ++i) {		// Calculates factorial
			factorial *= i;
		}
		if (i % 2 == 0) {
			cos += pow(x, p) / factorial;
		}
		else {
			cos -= pow(x, p) / factorial;
		}
		p += 2;
	}
	cos = cos / sqrt(1.0 - pow(cos, 2));		// Calculates tg
	std::cout << "Result: " << cos;
	return;
}
