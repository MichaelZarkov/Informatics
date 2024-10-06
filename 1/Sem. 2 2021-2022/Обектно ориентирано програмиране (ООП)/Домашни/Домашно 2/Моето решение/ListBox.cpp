
#include <iostream>
#include "HelperFunctions.h"
#include "ListBox.h"

ListBox::ListBox(char const* options, unsigned row, unsigned col)
	: Control("\0", row, col, 1, 0), options(nullptr), selectedOption(0), optionCount(0)
{
	changeText(options);
}
ListBox::ListBox(const ListBox& other) : Control(other) {
	copy(other);
}
ListBox::~ListBox() {
	free();
}

ControlType ListBox::getControlType() const {
	return ControlType::InputControl;
}

// ВАЖНО! Ако текстът се промени, то и размерите на контролата се променят.
// Тази функция заедно с текста променя и размерите.
void ListBox::changeText(const char* newOptions) {
	if (!newOptions)
		throw "Dereferencing nullptr!";

	unsigned notUsed1, notUsed2;
	textFormatingInRows(newOptions, optionCount, notUsed1, notUsed2);
	if (optionCount == 0)
		throw "Empty string!";

	free();
	// Запиши опциите.
	options = new String[optionCount];
	for (unsigned i = 0; i < optionCount; ++i) {
		newOptions = skipChars(newOptions, '\n');
		unsigned optionLen = lenTillTerm(newOptions, '\n');
		options[i] = { newOptions, optionLen};
		newOptions += optionLen;
	}

	size.y = options[selectedOption].getSize();    // Коригирай ширината.
}
void ListBox::consoleUserInput() {
	std::cout << "--- Change the state of a List Box ---\n"
		<< "    Control ID: " << id << "\n"
		<< "    Options:\n";
	for (unsigned i = 0; i < optionCount; ++i) {
		std::cout << options[i];
		std::cout << std::endl;
	}
		
	std::cout << "    Currently checked is: " << options[selectedOption] << "\n"
		<< "    Type the number of the option you want to check: ";

	unsigned num = 0;
	std::cin >> num;
	--num;
	if (!std::cin.good() || optionCount <= num)
		std::cout << "    Invalid number! The checked option was NOT changed.\n";
	else {
		selectedOption = num;
		std::cout << "    You checked option " << options[selectedOption] << ".\n";
	}

	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
void ListBox::printUserInput() const {
	std::cout << id << " " << options[selectedOption];
}

Control* ListBox::clone() const {
	return new ListBox{ *this };
}

void ListBox::writeInPosition(char* page, unsigned columns) const {
	if (!page)
		throw "Dereferencing nullptr!";

	unsigned positionInPage = position.x * columns + position.y;
	strcpyWON(page + positionInPage, options[selectedOption].getCString());			// Copy without '\0'.
}


void ListBox::copy(const ListBox& other) {
	selectedOption = other.selectedOption;
	optionCount = other.optionCount;
	options = new String[optionCount];
	for (unsigned i = 0; i < optionCount; ++i)
		options[i] = other.options[i];
}
void ListBox::free() {
	delete[] options;
}
