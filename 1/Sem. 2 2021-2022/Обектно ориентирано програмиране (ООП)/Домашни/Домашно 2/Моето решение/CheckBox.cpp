
#include <iostream>
#include <numeric>
#include "CheckBox.h"
#include "HelperFunctions.h"


CheckBox::CheckBox(const char* text, unsigned row, unsigned col)
	: Control("\0", row, col, 1, 0), isChecked(false)
{
	changeText(text);
}

ControlType CheckBox::getControlType() const {
	return ControlType::InputControl;
}

void CheckBox::changeText(const char* newText) {
	if (!newText)
		throw "Dereferencing nullptr!";

	unsigned numOfChars = lenTillTerm(newText, '\n');

	if (numOfChars == 0)
		throw "Empty string!";

	this->text = { newText, numOfChars };
	size.y = numOfChars + 4;	// Запази променената големина.
}
void CheckBox::consoleUserInput() {
	std::cout << "--- Change the state of a Check Box ---\n"
		      << "    Control ID: " << id << "\n"
		      << "    Checkbox text: " << "[" << (isChecked ? "X" : " ") << "] " << text << "\n"
	          << "    Type '1' to check it, type anything else to uncheck it: ";

	char c = '\0';
	std::cin.get(c);
	if (c == '1') {
		isChecked = true;
		std::cout << "    You checked the check box :)" << std::endl;
	}
	else {
		isChecked = false;
		std::cout << "    You unchecked the check box." << std::endl;
	}

	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    // <numeric>
}
void CheckBox::printUserInput() const {
	std::cout << id << " " << (isChecked ? "Checked" : "Not Checked");
}

Control* CheckBox::clone() const {
	return new CheckBox{ *this };
}

// Записва контролата на определената и позиция.
void CheckBox::writeInPosition(char* page, unsigned columns) const {
	if (!page)
		throw "Dereferencing nullptr!";

	unsigned positionInPage = position.x * columns + position.y;
	strcpyWON(page + positionInPage, "[ ] ");
	strcpyWON(page + positionInPage + 4, text.getCString());			// Copy without '\0'.
	if (isChecked)
		page[positionInPage + 1] = 'X';
}