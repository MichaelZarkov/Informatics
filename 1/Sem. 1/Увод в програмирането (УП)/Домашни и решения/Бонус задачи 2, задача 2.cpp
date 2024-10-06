
#include <iostream>
using namespace std;

long long input() {
	long long N;
	
	do {
		cout << "N=";
		cin >> N;
	} while (N < 0);

	return N;
}

int main()
{
	long long int N = input();

	bool dig[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	do {
		dig[N % 10] = true;
		N /= 10;
	} while (N != 0);

	for (int i = 0; i < 10; ++i) {
		N += dig[i];
	}

	cout << N << " diferent digits";
}