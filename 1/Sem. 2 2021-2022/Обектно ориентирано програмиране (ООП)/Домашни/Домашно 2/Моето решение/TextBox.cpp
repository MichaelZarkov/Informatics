
#include <iostream>
#include <numeric>
#include <cstring>
#include "TextBox.h"

unsigned const TextBox::BUFF_SIZE = 512;

TextBox::TextBox(char const* text, unsigned posRow, unsigned posCol, unsigned height, unsigned width)
	: Control(text, posRow, posCol, height, width)
{
	if (!height || !width)
		throw "Invalid Text box dimensions!";
}

ControlType TextBox::getControlType() const {
	return ControlType::IOControl;
}

void TextBox::changeText(const char* newText) {
	this->text = newText;    // Запазва целия текст.
}
void TextBox::consoleUserInput() {
	std::cout << "--- Change the state of a Text Box ---\n"
		<< "    Control ID: " << id << "\n"
		<< "    Terminating character is '#'\n"
	    << "    Write the new text: ";

	char temp[BUFF_SIZE];
	std::cin.get(temp, BUFF_SIZE, '#');

	this->text = temp;

	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
void TextBox::printUserInput() const {
	std::cout << id << " " << text;
}

Control* TextBox::clone() const {
	return new TextBox{ *this };
}

void TextBox::writeInPosition(char* page, unsigned columns) const {
	if (!page)
		throw "Dereferencing nullptr!";

	char const* t = text.getCString();
	for (unsigned rowIndex = 0; rowIndex < size.x && *t != '\0'; ++rowIndex) {
		char* posOfOptionInPage = page + (position.x + rowIndex) * columns + position.y;

		// Изведи ред с максимална дължина, колкото е ширината на TextBox.
		unsigned colIndex = 0;
		while (*t != '\n' && *t != '\0' && colIndex < size.y) {
			*posOfOptionInPage = *t;
			++t;
			++posOfOptionInPage;
			++colIndex;
		}
		
		if (*t == '\0')
			break;
		
		++t;

		if (colIndex >= size.y) {               // Ако ширината на TextBox е по - малка от ширината на текущия ред, стигни до следващия ред.
			char const* temp = strchr(t, '\n');
			if (!temp) {                        // Стигнали сме до края на текста('strchr' връща nullptr).
				break;
			}
			t = temp;
			++t;   // Презкочи '\n'.
		}
	}
}