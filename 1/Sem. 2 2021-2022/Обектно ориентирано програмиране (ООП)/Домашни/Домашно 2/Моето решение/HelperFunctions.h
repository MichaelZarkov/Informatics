#pragma once

// Same as 'strcpy()' but does NOT copy the terminating null character.
// WON - without null char.
void strcpyWON(char*, const char*);

// Returns the number of characters before the given terminating character or before '\0' is reached.
// The terminating character is not counted.
unsigned lenTillTerm(const char*, char);

// Връща указател към първата позиция, на която символът е различен от подадения.
// Ако се достигне '\0' връща указател него.
char const* skipChars(char const*, char);

// По подаден текст функцията:
//    - преброява редовете в него. Редът трябва да има текст, т.е за ред се счита <текст>'\n'.
//      Ако има няколко знака за нов ред "\n\n\n" един след друг, те се пропускат и не се броят за отделни редове.
//    - намира дължината на най-дългия ред.
//    - намира броя на всички символи, които не са '\n' (т.е все едно "strlen(text) - count_of_'\n'_in_text".
//      (т.е без повторения на нови редове "\n\n").
//    - връща горните три по подадените референции.
void textFormatingInRows(char const* text, unsigned& rowCount, unsigned& StringLength, unsigned& longestRowLen);