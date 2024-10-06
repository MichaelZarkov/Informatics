#include <iostream>

/*	Task 1	*/

// Tests: z y x w v u t s r q p o n m l k j i h g f e d c b a#
//		  Z Y X W V U T S R Q P O N M L K J I H G F E D C B A#

const int string_size = 1000000;
const int max_word_length = 64;
const int max_distinct_words = 1024;

void ErrorMsg() {
	std::cout << "\nFail to allocate memory!\n";
	return;
}

void TextInput(char* text) {
	std::cout << "\nWrite some text:\n";
	std::cin.get(text, string_size, '#');
	//std::cin.get();
	return;
}

void PrintText(const char* text) {
	std::cout << text;
	return;
}

void PrintTextInfo(const char* text, char** words, const int* friquencyOfWords, const int allWords, const int distinctWords) {

	std::cout << "\n\nAll words = " << allWords << "\nDistinct words = " << distinctWords 
			  << "\n\nAll the distinct words in the text and their friquency:\n";
	for (size_t i = 0; i < distinctWords; ++i) {
		std::cout << words[i] << " - " << friquencyOfWords[i] << "\n";
	}
	
	return;
}

char* AllocateMemoryForText() {
	char* text = new(std::nothrow) char[string_size];
	if (!text)
		return nullptr;
	return text;
}

char** AllocateMemoryForWords() {
	char** words = new(std::nothrow) char* [max_distinct_words];
	if (!words)
		return nullptr;
	words[0] = new(std::nothrow) char[max_distinct_words * max_word_length];
	if (!words) {
		delete[] words;
		return nullptr;
	}

	for (size_t i = 1; i < max_distinct_words; ++i)
		words[i] = words[i - 1] + max_word_length;

	return words;
}

int* AllocateMemoryForWordCount() {
	int* friquencyOfWords = new(std::nothrow) int[max_distinct_words];
	if (!friquencyOfWords)
		return nullptr;
	for (size_t i = 0; i < max_distinct_words; ++i)
		friquencyOfWords[i] = 0;
	return friquencyOfWords;
}

void DeleteMemory(char* text, char** words, int* nums) {

	if (text)
		delete[] text;

	if (words) {
		delete[] * words;
		delete[] words;
	}
	
	if (nums)
		delete[] nums;

	return;
}

// Returns true if the char is a letter or "-".
bool IsItALetter(const char C) {
	return ('a' <= C && C <= 'z') ||
		   ('A' <= C && C <= 'Z') ||
		   (C == '-');
}

// Returns true if the char is an upper case letter.
bool IsLetterUpperCase(const char C) {
	return ('A' <= C && C <= 'Z');
}

// Compares two strings in lexicographic order
// The result is 0 if the strings are equal,
// negative, if the first is before the second
// and positive in the other case.
int CompareWordsLexicographicly(const char* word1, const char* word2) {
	while (*word1 && *word1 == *word2) {
		++word1;
		++word2;
	}
	return *word1 - *word2;
}

// Returns the index of the maximal element in a range.
int MaxEl(int* friquencyOfWords, int from, int to) {
	
	int max = from;
	for (int i = from + 1; i < to; ++i) {
		if (friquencyOfWords[i] > friquencyOfWords[max])
			max = i;
	}
	return max;
}

void Swap(int* friquencyOfWords, int i, int j) {		// should try the swaping with pointers only
	int t = friquencyOfWords[i];
	friquencyOfWords[i] = friquencyOfWords[j];
	friquencyOfWords[j] = t;
	return;
}

// Swap words by swaping their pointers.
void SwapPointers(char*& pWord1, char*& pWord2) {
	char* t = pWord1;
	pWord1 = pWord2;
	pWord2 = t;
	return;
}

/*
// Swap words by swaping the entire words.
void SwapWords(char* word1, char* word2) {		// should try the swaping with pointers only
	char swap_word[64];
	strcpy(swap_word, word1);
	strcpy(word1, word2);
	strcpy(word2, swap_word);
	return;
}
*/

// Sorts words lexicographicly in a given range.
// Selection sort.
void SortLex(char** words, int* frqOfWords, int from, int to) {
	for (int i = from; i < to - 1; ++i) {
		int m = i;
		for (int j = i + 1; j < to; ++j) {
			if (CompareWordsLexicographicly(words[m], words[j]) > 0)	// first word is the currently "shortest" lexicographicly
				m = j;
		}
		Swap(frqOfWords, m, i);
		SwapPointers(words[m], words[i]);
		//SwapWords(words[m], words[i]);
	}
}

// Counts all words.
// Counts the number of distinct words.
// Counts how many times each word repeats.
// Puts the words without their duplicates in an matrix.
void ExtractAndCountWords(char* text, char** words, int* friquencyOfWords, int& allWords, int& distinctWords) {

	do {
		// got the begining of a word
		while (*text && !IsItALetter(*text)) {
			++text;
		}
		if (!*text)
			break;
		
		// write the word to 'words'
		int i;
		for (i = 0; *text && IsItALetter(*text); ++i, ++text) {
			if (IsLetterUpperCase(*text))
				words[distinctWords][i] = *text + 32;		// change letter to lower case
			else
				words[distinctWords][i] = *text;
		}
		words[distinctWords][i] = 0;		// put a zero at the end of the word
		++allWords;		// count the word

		// checks if there is already the same word in 'words'
		bool is_duplicate = false;
		for (i = 0; i < distinctWords; ++i) {
			if (!CompareWordsLexicographicly(words[i], words[distinctWords])) {
				is_duplicate = true;
				++friquencyOfWords[i];		// count it as a duplicate word
				break;
			}
		}
		// count it as a separate word
		if (!is_duplicate) {
			++friquencyOfWords[distinctWords];
			++distinctWords;
		}

	} while (*text);

	return;
}

// Sorts the words by how often they appear in the text in descending order.
// Selection sort.
void SortByFriquency(char** words, int* friquencyOfWords,const int distinctWords) {
	for (int i = 0; i < distinctWords - 1; ++i) {
		int m = MaxEl(friquencyOfWords, i, distinctWords);
		Swap(friquencyOfWords, m, i);
		SwapPointers(words[m], words[i]);
		//SwapWords(words[m], words[i]);
	}
	return;
}

void SortLexicographicly(char** words, int* frqOfWords,const int distinctWords) {
	int from = 0;

	do {
		int to = from + 1;
		while ((frqOfWords[from] == frqOfWords[to]) && (to < distinctWords))
			++to;
		SortLex(words, frqOfWords, from, to);
		from = to;
	} while (from != distinctWords);

	return;
}

int main()
{
	char* text = AllocateMemoryForText();
	if (!text) {
		ErrorMsg();
		return 1;
	}
		
	char** words = AllocateMemoryForWords();
	if (!words) {
		DeleteMemory(text, nullptr, nullptr);
		ErrorMsg();
		return 1;
	}
	char* words_begining = *words;	// this is here bacause later the array of pointers '*words' gets shuffled

	int* friquencyOfWords = AllocateMemoryForWordCount();
	if (!friquencyOfWords) { 
		DeleteMemory(text, words, nullptr);
		ErrorMsg();
		return 1; 
	}
		

	TextInput(text);
	//PrintText(text);

	int allWords = 0, distinctWords = 0;
	ExtractAndCountWords(text, words, friquencyOfWords, allWords, distinctWords);

	SortByFriquency(words, friquencyOfWords, distinctWords);

	SortLexicographicly(words, friquencyOfWords, distinctWords);

	PrintTextInfo(text, words, friquencyOfWords, allWords, distinctWords);


	
	*words = words_begining;
	DeleteMemory(text, words, friquencyOfWords);
	return 0;
}
