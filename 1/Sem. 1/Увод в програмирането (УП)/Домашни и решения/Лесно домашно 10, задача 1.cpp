// Lesno domashno 10, zadacha 1

#include <iostream>

int input() {
    int N;
    do {
        std::cout << "N=";
        std::cin >> N;
    } while (N < 0);
    
    return N;
}

// Finds if there is at least one digit in 'n' the same as 'dig' (dig = [0,9])
bool rep_digit(int n, int dig) {   
    if (n == 0)
        return false;
    if (dig == n % 10)
        return true;
    return rep_digit(n / 10, dig);
}

bool recursion(int N) {
    if (N == 0)
        return false;
    if (rep_digit(N / 10, N % 10))
        return true;
    return recursion(N / 10);
}

int main()
{
    int N = input();        // Must be N >= 0
    if (recursion(N))
        std::cout << "There are repeating digits in " << N;
    else
        std::cout << "There are NO repeating digits in " << N;
    return 0;
}


/* Without recursion

bool find_rep_dig(int N) {

    while (N != 0) {
        int dig = N % 10;
        int n = N / 10;

        while (n != 0) {
            if (n % 10 == dig)
                return true;
            n /= 10;
        }

        N /= 10;
    }

    return false;
}
*/