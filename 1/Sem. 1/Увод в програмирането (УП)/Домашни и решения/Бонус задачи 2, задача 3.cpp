// Bonus zadachi 2, zadacha 3
// Fun stuff with prime numbers

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// Keyboard input for 'N'
int input() {
	int N;
	do {
		cout << "N=";
		cin >> N;
		if (N < 2)
			cout << "N must be N > 1. Try again.\n";
	} while (N < 2);

	return N;
}

// Checks if a number is prime
bool checkPrime(int N) {	
	if (N == 2)
		return true;

	if (N % 2 == 0)
		return false;

	for (int j = 3; j * j <= N; j += 2) {
		if (N % j == 0)
			return false;
	}

	return true;
}

// Returns x + y
//
// x = p1*p2*...*pn < N
// y = p1*p2*...*pn*p(n+1) >= N
// (p1, p2,..., p(n+1)) - consecutive prime numbers starting from 2 (p1 = 2)
void partialPrimeSum(int N, int* pps) {
	int x = 1;

	for (int i = 2; true; ++i) {
		if (checkPrime(i)) {
			cout << "i=" << i <<endl;
			if (x * i < N)
				x *= i;
			else {
				pps[0] = x + (x * i);
				pps[1] = i;
				return;
			}
		}
	}
}

// 2^M <= x + y
// Finds if M is <,> or = to p(n+1)
// See 'partialPrimeSums()' for the def. of p(n+1)
void powersOfTwo(int* pps) {
	int M = 0, two = 2;
	while (two <= pps[0]) {
		two *= 2;
		++M;
	}

	if (M > pps[1]) {
		cout << "M is more than the last prime of the product: " << M << " > " << pps[1];
		return;
	}
	if (M < pps[1]) {
		cout << "M is less than the last prime of the product: " << M << " < " << pps[1];
		return;
	}

	cout << "M is equal to the last prime of the product: " << M << " = " << pps[1];
}

int main()
{	
	int N = input();

	int pps[2];
	partialPrimeSum(N, pps);
	powersOfTwo(pps);
	
}