
#include "Label.h"
#include "HelperFunctions.h"


Label::Label(const char* text, unsigned row, unsigned col) 
	: Control("\0", row, col, 1, 0)
{
	changeText(text);
}

ControlType Label::getControlType() const {
	return ControlType::OutputControl;
}

void Label::changeText(const char* text) {
	if (!text)
		throw "Dereferencing nullptr!";

	unsigned numOfChars = lenTillTerm(text, '\n');

	if (numOfChars == 0)
		throw "Empty string!";

	this->text = {text, numOfChars};    // Save the first line.
	size.y = numOfChars;                         // Update the size.
}
void Label::consoleUserInput() {
	throw "This function is defined only for input controls!";
}
void Label::printUserInput() const {
	throw "Not an input control!";
}

Control* Label::clone() const {
	return new Label{ *this };
}

// Записва контролата на определената и позиция.
// Ако има нещо записано на същата позиция, то се трие и се презаписва(overwrite).
void Label::writeInPosition(char* page, unsigned columns) const {
	if (!page)
		throw "Dereferencing nullptr!";

	unsigned positionInPage = position.x * columns + position.y;
	strcpyWON(page + positionInPage, text.getCString());			// Copy without '\0'.
}