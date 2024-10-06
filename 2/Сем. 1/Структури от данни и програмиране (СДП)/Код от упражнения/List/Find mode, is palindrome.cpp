// Author: Michael Zarkov
//
// Main goal is to excercise working with std::list and iterators.
// 
// Task 1: Find the mode in a linked list (the element with the most appearances).
//
// Task 2: Check if a list is palindrome.

#include <iostream>
#include <list>
#include <cstdlib>  // rand()
#include <ctime>
#include <vector>


template <class T>
void printList(std::list<T>& l)
{
	auto i = l.begin();
	while (i != l.end())
	{
		std::cout << *i << ", ";
		++i;
	}
}

void fillRandList(std::list<size_t>& l)
{
	std::list<size_t>::iterator i = l.begin();
	while (i != l.end())
	{
		*i = rand() % 3;
		++i;
	}
}

void fillRandList(std::list<char>& l)
{
	std::list<char>::iterator i = l.begin();
	while (i != l.end())
	{
		*i = 65 + rand() % 26;
		++i;
	}
}

// Time complexity O(nlogn)
// First sort the list then go through the sorted list and find the mode.
size_t findMode(std::list<size_t>& l)
{
	if (l.empty())
		return 0;

	l.sort();
	std::cout << std::endl;

	std::list<size_t>::iterator it = ++l.begin();
	size_t prevElement = l.front();
	size_t currentCount = 1, highestCount = 1;
	while (it != l.end())
	{
		if (prevElement == *it)
		{
			++currentCount;
		}
		else
		{
			if (currentCount > highestCount)
				highestCount = currentCount;

			prevElement = *it;
			currentCount = 1;
		}
		
		++it;
	}
	
	if (currentCount > highestCount)
		return currentCount;
	else
		return highestCount;
}

bool isPalindrome(const std::list<char>& l)
{
	auto beg = l.cbegin();
	auto end = l.crbegin();
	for (size_t i = 0; i < l.size() / 2; ++i)
	{
		if (*beg != *end)
			return false;

		++beg;
		++end;
	}

	return true;
}

int main()
{

	srand(time(0));

	// Find mode.
	/*std::list<size_t> l(7);
	fillRandList(l);
	printList(l);
	std::cout << std::endl << "Mode: " << findMode(l);*/

	// Is palindrome.
	std::list<char> l(3);
	for (size_t i = 0; i < 30; ++i)
	{
		fillRandList(l);
		printList(l);
		std::cout << std::endl << "Is palindrome: " << (isPalindrome(l) ? "true" : "false") << std::endl;
	}
}