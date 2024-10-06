// Author: Michael Zarkov
//
// The focus of this task is working with iterators.
// 
// Tast: print the Gray code sequences up to a given number N.
//
// What is Gray code: The reflected binary code (RBC), also known as reflected binary (RB) or Gray code
//                    after Frank Gray, is an ordering of the binary numeral system such that two successive
//                    values differ in only one bit (binary digit).
// 
// How to generate the Gray code for N+1 if given the gray code for N:
// Take the Gray code for N, add 0 in front of every number and write it down (1).
// Next, take the Gray code for N in reverse order and add 1 to the front of every number (2).
// The Gray code for N+1 is (1) followed by (2)
// Ex:
//     N = 1, Gray code: 0 1
//     N = 2, Gray code: 00 01 11 10
//     N = 3, Gray code: 000 001 011 010 110 111 101 100
//     N = 4, Gray code: 0000 0001 0011 0010 0110 0111 0101 0100 1100 1101 1111 1110 1010 1011 1001 1000
//     and so on . . .


#include <iostream>
#include <list>
#include <string>

template <class T>
void print(std::list<T>& l) {
	for (auto i = l.begin(); i != l.end(); ++i) {
		std::cout << *i << " ";
	}
	std::cout << std::endl << std::endl;
}

// Expects valid Gray code sequence in 'gray_code'.
// Saves next Gray code sequence in 'gray_code'.
void next_gray_code(std::list<std::string>& gray_code)
{
	std::list<std::string> second_halve;
	for (auto it = gray_code.crbegin(); it != gray_code.crend(); ++it)
	{
		second_halve.push_back('1' + *it);
	}

	for (auto it = gray_code.begin(); it != gray_code.end(); ++it)
	{
		*it = '0' + *it;
	}

	gray_code.splice(gray_code.end(), second_halve);
}

void Gray_code(size_t N)
{
	std::cout << "0\n\n";
	
	if (!N)
		return;
	
	std::list<std::string> gray_code{ "0", "1" };

	print(gray_code);

	for (size_t i = 1; i < N; ++i)
	{
		next_gray_code(gray_code);
		print(gray_code);
	}
}

int main()
{
	Gray_code(4);
}