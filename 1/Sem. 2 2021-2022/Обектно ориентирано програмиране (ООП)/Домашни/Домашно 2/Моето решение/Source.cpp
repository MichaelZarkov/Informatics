
#include <fstream>
#include "Form.h"
#include "Label.h"
#include "CheckBox.h"
#include "RadioButton.h"
#include "TextBox.h"
#include "ListBox.h"

int main()
{
	/*
	    Можеш да промениш запълващия символ във формата от функцията
		"char* makeEmptyPage(unsigned Row, unsigned Col)" във "Form.cpp".

	    Примерен вход:
		1
		2
		New text#
		3

	*/
	Label l1{ "Form from Michael Zarkov (label).", 0, 0 };
	Label l2{ "This is a label (label).", 0, 45 };
	Label l3{ "Choose an option: (label)", 2, 0 };

	RadioButton r1{ "1. I like cats (radio button)\n2. I like dogs (radio button)\n3. I like cats and dogs (radio button)", 3, 1 };

	CheckBox cb1{ "Check this check box (check box).", 8, 0 };
		
	TextBox tb1{ "This is my new text box (text box).\nWill this whole row get printed or not?\nWhat about this row?", 12, 0, 2, 34 };

	ListBox ls1{ "I like cars (list box)\nI don't like cars (list box)", 10, 0 };
	

	Form f;
	f.addControl(l1);
	f.addControl(l2);
	f.addControl(l3);
	f.addControl(cb1);
	f.addControl(r1);
	f.addControl(tb1);
	f.addControl(ls1);

	std::cout << f;
	std::cout << std::endl << std::endl;
	f.printInfoFromInputControls();
	std::cout << std::endl;
	f.userInput();
	std::cout << std::endl;
	std::cout << f;
	std::cout << std::endl;
	f.printInfoFromInputControls();
	std::cout << std::endl;

	std::ofstream file("MyFile.txt");
	file << f;			// write form to file.
}