#include <iostream>
#include <ctime>
#include <algorithm>
	
		/*	Task 2	*/

const int max_word_length = 100;


//------------------------------ Common functions ------------------------------

void Error() {
	std::cout << "\nFail to allocate memory!\n";
	return;
}

void Delete(char** dict, int i, char** table) {

	if (dict) {
		for (int j = 0; j < i; ++j)
			delete[] dict[j];
		delete[] dict;
	}

	if (table) {
		delete[] * table;
		delete[] table;
	}

	return;
}

// Returns positive if the second is before the first.
int CompareLexic(char* word1, char* word2) {

	while (*word1 && *word1 == *word2) {
		++word1;
		++word2;
	}
	return *word1 - *word2;
}

//------------------------------ Common functions ------------------------------



//--------------------------------- Dictionary ---------------------------------

// Input for the number of words in the dictionary.
int WordNumber() {

	int N;
	do {
		std::cout << "How many words. N = ";
		std::cin >> N;
		if (N <= 0)
			std::cout << "N must be a positive integer! Try again.\n";
	} while (N <= 0);

	return N;
}

// Returns true if the string contains only upper or lower case letters.
bool IsItAWord(char* word) {
	
	while (*word) {
		if (!(('a' <= *word && *word <= 'z') || ('A' <= *word && *word <= 'Z')))
			return false;
		++word;
	}

	return true;
}

// Changes the upper case to lower case letters in a word.
void ChangeLetters(char* word) {

	while (*word) {
		if ('A' <= *word && *word <= 'Z')
			*word += 32;
		++word;
	}

	return;
}

// Return true if the dictionary is filled up correctly.
// Returns false if there is an error when allocating memory.
bool InputWords(char** dict, const int N) {

	char* word = new(std::nothrow) char[max_word_length];
	if (!word)
		return false;

	std::cout << "\nWrite the words:\n";
	for (int i = 0; i < N; ++i) {
		std::cin.ignore();
		std::cin.get(word, max_word_length);	// get word
		
		// Check if the word contains only letters.
		if (!IsItAWord(word)) {
			--i;
			std::cout << "Invalid word! Try again.\n";
			continue;
		}

		// Check lexicographic order.
		ChangeLetters(word);
		if (i != 0 && 0 < CompareLexic(dict[i - 1], word)) {
			--i;
			std::cout << "Invalid lexicographically! Try again.\n";
			continue;
		}

		// Allocate memory for the word.
		dict[i] = new(std::nothrow) char[strlen(word)];
		if (!dict[i]) {
			Delete(dict, i, nullptr);
			return false;
		}

		strcpy(dict[i], word);
	}

	delete[] word;
	return true;
}

//--------------------------------- Dictionary ---------------------------------



//--------------------------------- Table game ---------------------------------

int ReadK() {
	int K;
	do {
		std::cout << "Table size. K = ";
		std::cin >> K;
		if (K < 2 || K > 5)
			std::cout << "K must be between 2 and 5. Try again.\n";
	} while (K < 2 || K > 5);

	return K;
}

char** ReadTable(int K) {
	// Allocate table.
	char** table = new(std::nothrow) char* [K];
	if (!table)
		return nullptr;
	*table = new(std::nothrow) char[K * K];
	if (!*table) {
		delete[] table;
		return nullptr;
	}
	for (int i = 1; i < K; ++i)
		table[i] = table[i - 1] + K;

	std::cout << "Write the table:\n";
	for (int i = 0; i < K * K; ++i) {
		std::cin >> (*table)[i];
		if (!('a' <= (*table)[i] && (*table)[i] <= 'z')) {
			--i;
			std::cout << "Invalid character. Try again.\n";
		}
	}

	return table;
}

// Returns true if the word is in from the dictionary.
bool IsItInDictionary(char** dict, char* word, int N) {

	for (int i = 0; i < N; ++i)
		if (!CompareLexic(dict[i], word))
			return true;
	
		return false;
}

bool CheckIfNextMoveIsValid(int K, int cur_point, int nxt_point) {

	if ((abs((cur_point % K) - (nxt_point % K)) <= 1) && 
		(abs(cur_point - nxt_point) <= K + 1))
	{
		return true;
	}

	return false;
}

// Returns false if there is an error with memory.
bool SmallTable(char** dict, char** table, const int N, const int K) {
	int x = rand() % (K * K);		// Choose random start point

	// ALLOCATIONS!!!
	char* word = new(std::nothrow) char[(K * K) + 1];
	if (!word)
		return false;
	int* perm = new(std::nothrow) int[K * K];
	if (!perm) {
		delete[] word;
		return false;
	}

	// Initial permutation
	perm[0] = x;
	for (int i = 1; i < K * K; ++i) {
		if (i <= x) {
			perm[i] = i - 1;
		}
		else
			perm[i] = i;
	}
	
	*word = (*table)[x];
	int cur_max = 0;	// current length of the longest found word
	do {
		// Create a char str from the permutation.
		int i = 1;
		for (i = 1; i < K * K; ++i) {
			word[i] = 0;
			int len = strlen(word);
			if (IsItInDictionary(dict, word, N) && len > cur_max) {
				cur_max = len;	// if it's longer than the current write it down
			}


			if (CheckIfNextMoveIsValid(K, perm[i - 1], perm[i])) {
				word[i] = (*table)[perm[i]];
			}
		}
		word[i] = 0;

		// Check if the char str is int the dictionary.
		int len = strlen(word);
		if (IsItInDictionary(dict, word, N) && len > cur_max) {
			cur_max = len;	// if it's longer than the current write it down
		}

	} while (std::next_permutation(perm + 1, perm + (K * K) - 1));	// generate permutation

	std::cout << "\nLongest word that can be constructed is: " << cur_max << "\n";

	int wordCount = 0;
	for (int i = 0; i < K * K; ++i)
		perm[i] = i;
	do {
		int i = 0;
		for (i = 0; i < cur_max; ++i) {
			word[i] = (*table)[perm[i]];
		}
		word[i] = 0;

		if (IsItInDictionary(dict, word, N))
			++wordCount;

	} while (std::next_permutation(perm, perm + K * K));

	std::cout << "The number of all words with length " << cur_max << " is: " << wordCount << std::endl;

	return true;
}

//--------------------------------- Table game ---------------------------------


int main()
{
	srand(time(0));

	int N = WordNumber();

	char** dict = new(std::nothrow) char* [N];
	if (!dict) {
		Error();
		return 1;
	}

	if (!InputWords(dict, N)) {
		Error();
		return 1;
	}

	int K = ReadK();
	char** table = ReadTable(K);
	if (!table) {
		Delete(dict, N, table);
		Error();
		return 1;
	}

	if (!SmallTable(dict, table, N, K)) {
		Delete(dict, N, table);
		Error();
		return 1;
	}
	

	return 0;
}