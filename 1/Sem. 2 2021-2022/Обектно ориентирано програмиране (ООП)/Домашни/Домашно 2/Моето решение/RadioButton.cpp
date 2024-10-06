
#include <iostream>
#include <numeric>
#include "RadioButton.h"
#include "HelperFunctions.h"


RadioButton::RadioButton(char const* options, unsigned row, unsigned col)
	: Control("\0", row, col, 0, 0), selectedOption(0)
{
	changeText(options);
}

ControlType RadioButton::getControlType() const {
	return ControlType::InputControl;
}

// ВАЖНО! Ако текстът се промени, то и размерите на контролата се променят.
// Тази функция заедно с текста променя и размерите.
void RadioButton::changeText(const char* newOptions) {
	if (!newOptions)
		throw "Dereferencing nullptr!";

	// В 'newOptions' опциите трябва да са разделени с нов ред.
	// Пр: <опция 1>'\n'<опция 2>'\n'<опция 3>'\n' . . . <опция к>'\0'

	unsigned optionsLength = 0;
	textFormatingInRows(newOptions, size.x, optionsLength, size.y);
	size.y += 4;	// За 4-те символа в началото.
	if (optionsLength == 0)
		throw "Empty 'options' string!";

	writeTheOptions(newOptions, optionsLength);
}
void RadioButton::consoleUserInput() {
	
	std::cout << "--- Change the state of a Radio Button ---\n"
		<< "    Control ID: " << id << "\n"
		<< "    Options:\n" << text << "\n"    // Това извеждане може да се подобри
		<< "    Currently checked is: ";
	
	if (selectedOption) 
		std::cout << selectedOption << "\n";
	else
		std::cout << "no option is checked.\n";

	std::cout << "    Type the number of the option, if you want to check it.\n"
		      << "    Type '0' if you want to uncheck the box: ";

	unsigned num = 0;
	std::cin >> num;
	if (!std::cin.good() || size.x < num)
		std::cout << "    Invalid number! The checked option was NOT changed.\n";
	else {
		selectedOption = num;
		if (num == 0)
			std::cout << "    You unchecked the option.\n";
		else
			std::cout << "    You checked option " << num << ".\n";
	}

	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
void RadioButton::printUserInput() const {
	std::cout << id << " ";
	
	if (!selectedOption) {
		std::cout << "No options selected.";
		return;
	}
		
	// Find the selected option.
	char const* options = text.getCString();
	unsigned i = 1;
	for (unsigned i = 1; i < selectedOption; ++i) {
		options = strchr(options, '\n');
		++options;		// Skip '\n'.
	}
	
	// Print the option.
	while (*options != '\n' && *options) {
		std::cout << *options;
		++options;
	}
}

Control* RadioButton::clone() const {
	return new RadioButton{ *this };
}

// Записва контролата на определената и позиция.
void RadioButton::writeInPosition(char* page, unsigned columns) const {
	if (!page)
		throw "Dereferencing nullptr!";

	// Запиши всички опции.
	char const* options = text.getCString();
	for (unsigned i = 0; i < size.x; ++i) {
		char* posOfOptionInPage = page + (position.x + i) * columns + position.y;
		
		strcpyWON(posOfOptionInPage, "[ ] ");
		
		// Запиши опцията.
		posOfOptionInPage += 4;
		while (*options != '\n' && *options != '\0') {
			*posOfOptionInPage = *options;
			++options;    
			++posOfOptionInPage;
		}
		++options;
	}

	// Запиши коя опция е отбелязана.
	if (selectedOption) {
		// Тези сметки щяха да се съкратят, ако бях ползвал двумерен масив.
		// Всъщност всичко без 'position.y + 1' служи за да се "стигне" до правилния ред.
		page[(position.x + selectedOption - 1) * columns + position.y + 1] = 'X';
	}
}

void RadioButton::writeTheOptions(char const* options, unsigned optionsStrLen) {

	text = "\0";                                // This frees the memory.
	text.resize(optionsStrLen + size.x - 1);	// Задели памет за опциите и разделителите '\n'.
	while (*options) {
		options = skipChars(options, '\n');    // Презкочи символите за нов ред.

		if (*options == '\0')
			break;

		while (*options != '\n' && *options) {
			text += *options;	// Запиши опцията.
			++options;
		}
		text += *options;		// Сложи '\n' м-у опциите.
	}
}