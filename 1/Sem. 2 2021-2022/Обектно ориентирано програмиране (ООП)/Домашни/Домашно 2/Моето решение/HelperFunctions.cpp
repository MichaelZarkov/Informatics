
#include "HelperFunctions.h"

void strcpyWON(char* dest, const char* source) {
	while (*source) {
		*dest = *source;
		
		++dest;
		++source;
	}
}

unsigned lenTillTerm(const char* source, char term) {
	unsigned count = 0;
	while (*source && *source != term) {
		++count;
		++source;
	}

	return count;
}

char const* skipChars(char const* source, char skipChar) {
	while (*source == skipChar && *source) {
		++source;
	}

	return source;
}

void textFormatingInRows(char const* text, unsigned& rowCount, unsigned& StringLength, unsigned& longestRowLen) {

	rowCount = 0, StringLength = 0, longestRowLen = 0;
	while (*text != '\0') {
		text = skipChars(text, '\n');    // Презкочи символите за нов ред.

		if (*text == '\0')
			break;

		++rowCount;

		unsigned currentOptionLen = lenTillTerm(text, '\n');  // Намери дължината на опцията.
		if (longestRowLen < currentOptionLen)
			longestRowLen = currentOptionLen;

		StringLength += currentOptionLen;
		text += currentOptionLen;			// Презкочи сегашната опция.
	}
}