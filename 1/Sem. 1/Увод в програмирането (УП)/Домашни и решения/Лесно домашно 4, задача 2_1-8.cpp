
//2. Finds biggest common divisor of 2 numbers.

#include <iostream>

void BiggestDivisor(int n1, int n2) {
	if ((n1 == 0) || (n2 == 0)) {		// Numbers can't be 0
		std::cout << "Numbers cannot be 0!";
		return;
	}

	if (n1 < n2) {		// Assigning the smaller of the 2 numbers to 'n2'
		int c = n2;
		n2 = n1;
		n1 = n2;
	}
	unsigned BD = 1;
	for (int i = 1; i <= n2; ++i) {		// Checking divisors up to the smaller of the 2 numbers
		if ((n1 % i == 0) && (n2 % i == 0)) {
			BD = i;
		}
	}
	std::cout << "Biggest common divisor is: " << BD;
}


//3. Calculates a to the power of b (a-intiger, b-whole number)

#include <iostream>

void negExponent(unsigned a, int b) {	// Function for negative exponents
	double product = 1;
	while (b != 0) {
		product *= a;
		++b;
	}
	product = 1 / product;
	std::cout << "Result: " << product;
	return;
}

void Power(unsigned a, int b) {
	if (a == 0) {		// 0 to any porew is 0
		std::cout << "Result: 0";
		return;
	}
	if (b < 0) {
		negExponent(a, b);
		return;
	}

	unsigned product = 1;
	while (b != 0) {		// Positive or 0 exponents
		product *= a;
		--b;
	}
	std::cout << "Result: " << product;
	return;
}


//4. Checks if a number is green

#include <iostream>


void greenNum(int a) {
	int b = a;
	int sum = 0;	// Sum of the cubes of the digits

	while (b != 0) {
		int dig = b % 10;
		sum += dig * dig * dig;
		b /= 10;
	}

	if (a == sum) {
		std::cout << "The number is green.";
	}
	else {
		std::cout << "The number is not green.";
	}
	return;
}


//5. Calculates the sum of the green numbers in a given interval.

#include <iostream>

void loopForInterval(int M, int N) {
	if (M > N) {
		int c = N;
		N = M;
		M = c;
	}

	int sum = 0;		// Sum of the green numbers
	while (M <= N) {
		int b = M;
		int a = 0;
		while (b != 0) {		// Calculates the sum of the cubes of the digits
			int dig = b % 10;
			a += dig * dig * dig;
			b /= 10;
		}
		if (M == a) {		// Checks if the current number is green
			sum += a;		// Adds to the sum of the green numbers
		}
		++M;
	}
	std::cout << "The sum is: " << sum;
	return;
}


//7. Calculates the sum of the green minus the sum of the red numbers in a given interval.

#include <iostream>

int redNumberCheck(int M, int N) {
	int sum = 0;
	while (M <= N) {
		int b = M;
		int a = 0;		// Sum of the digits of the current number
		while (b != 0) {	// Calculates the sum of the digits
			a += b % 10;
			b /= 10;
		}
		if (a != 0) {
			if (M % a == 0) {		// Checks if 'a' is a multiple of 'M' 
				sum += M;
			}
		}
		++M;
	}
	return sum;
}

void RedAndGreen(int M, int N) {
	if (M > N) {
		int c = N;
		N = M;
		M = c;
	}
	int sumR = redNumberCheck(M, N);		// Sum of the red numbers
	int sum = 0;		// Sum of the green numbers
	while (M <= N) {
		int b = M;
		int a = 0;
		while (b != 0) {		// Calculates the sum of the cubes of the digits
			int dig = b % 10;
			a += dig * dig * dig;
			b /= 10;
		}
		if (M == a) {		// Checks if the current number is green
			sum += a;		// Adds to the sum of the green numbers
		}
		++M;
	}
	std::cout << "The sum is: " << sum - sumR;
	return;
}


//8. Finds the sum: 1 - x^2/2! + x^4/4! - x^6/6! +..., by given 'x' and 'n' (n - number of terms)

#include <iostream>
#include <cmath>

void sum(double x, int n) {
	double sum = 1.0;
	double p = 2;
	for (int i = 1; i <= n; ++i) {
		double factorial = 1;
		for (int i = 1; i <= p; ++i) {		// Calculates factorial
			factorial *= i;
		}
		if (i % 2 == 0) {
			sum += pow(x, p) / factorial;		// +x^p/p!
		}
		else {
			sum -= pow(x, p) / factorial;		// -x^p/p!
		}
		p += 2;
	}
	std::cout << "Result: " << sum;
	return;
}



