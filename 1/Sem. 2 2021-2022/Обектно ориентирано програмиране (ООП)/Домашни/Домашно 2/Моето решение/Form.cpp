
#include <iostream>
#include "Form.h"


Form::Form() : controls(nullptr), capacity(8), size(0) {
	controls = new Control * [capacity];
}
Form::Form(const Form& other) {
	copy(other);
}
Form& Form::operator=(const Form& other) {
	if (this != &other) {
		free();
		copy(other);
	}

	return *this;
}
Form::~Form() {
	free();
}

char* makeEmptyPage(unsigned Row, unsigned Col) {
	/*
	    Създава символен низ от вида:
		  
		        Col + 1
		      .........'\n'
		      .........'\n'
		 Row  .........'\n'
		      .........'\n'
		      .........'\0'

		Колините са 'Col + 1' на брой, като на мясо 'Col + 1' има '\n'.
	*/

	if (Row == 0 || Col == 0)
		return nullptr;

	++Col;    // Заради новия ред в края на всеки ред.
	char* Page = new char[Row * Col];
	for (unsigned i = 0; i < Row * Col; ++i)
		Page[i] = { ' ' };		// "Изпразни" страницата(при порверка за грешки просто замени ' ' с нещо, което се вижда на пр. '*').

	for (unsigned i = Col - 1; i < Row * Col; i += Col)
		Page[i] = '\n';		    // Сложи новите редове.

	Page[Row * Col - 1] = '\0';
	
	return Page;
}
std::ostream& operator<<(std::ostream& os, const Form& f) {
	unsigned Rows = 0, Cols = 0;
	f.rowsAndCols(Rows, Cols);

	// Евентуално да проверя дали има застъпващи си контроли
	// и да предупредя за проблем при извеждане.

	char* FormPage = makeEmptyPage(Rows, Cols);
	if (!FormPage)
		return os;

	for (unsigned i = 0; i < f.size; ++i)
		f.controls[i]->writeInPosition(FormPage, Cols + 1);	// Write the controls in 'FormPage'.
	
	os << "--- Print the whole form ---\n";    // Това може да се закоментира, ако искаш само и единствено текста на формата.
	os << FormPage;

	delete[] FormPage;

	return os;
}
Control* Form::operator[](unsigned controlID) {
	for (unsigned i = 0; i < size; ++i)
		if (controls[i]->getID() == controlID)
			return controls[i];

	return nullptr;
}
const Control* Form::operator[](unsigned controlID) const {
	for (unsigned i = 0; i < size; ++i)
		if (controls[i]->getID() == controlID)
			return controls[i];

	return nullptr;
}

void Form::addControl(const Control& newControl) {
	if (capacity <= size)
		resize();

	controls[size] = newControl.clone();
	++size;
}
void Form::userInput() const {
	std::cout << "--- Please enter the required information for the Form ---\n";
	
	for (unsigned i = 0; i < size; ++i) {
		if (controls[i]->getControlType() == ControlType::InputControl ||
			controls[i]->getControlType() == ControlType::IOControl)
		{
			controls[i]->consoleUserInput();
		}
	}
}
void Form::changeText(const char* newText, unsigned controlID) {
	Control* c = this->operator[](controlID);
	
	if (!c)
		throw "There is no output control in this Form with the give ID!";
	
	if (c->getControlType() != ControlType::OutputControl)
		throw "The control with the given ID is not an Output control!";

	c->changeText(newText);		// Ако 'changeText' хвърля исзкючения, да ги хвана може би ???
}
void Form::printInfoFromInputControls() const {
	std::cout << "--- Print information from all input controls ---\n";
	for (unsigned i = 0; i < size; ++i) {
		if (controls[i]->getControlType() == ControlType::InputControl ||
			controls[i]->getControlType() == ControlType::IOControl)
		{
			controls[i]->printUserInput();
			std::cout << std::endl;
		}
	}
}

void Form::free() {
	for (unsigned i = 0; i < size; ++i)
		delete controls[i];

	delete[] controls;
}
void Form::copy(const Form& other) {
	size = other.size;
	capacity = other.capacity;

	controls = new Control * [capacity];
	for (unsigned i = 0; i < size; ++i)
		controls[i] = other.controls[i]->clone();
}
void Form::resize() {
	capacity *= 2;
	Control** newControls = new Control * [capacity];
	
	for (unsigned i = 0; i < size; ++i)
		newControls[i] = controls[i];

	delete[] controls;
	controls = newControls;
}

// Обръщам внимание, че 'lastRow' и 'lastCol' са референции.
void Form::rowsAndCols(unsigned& lastRow, unsigned& lastCol) const {
	
	lastRow = 0, lastCol = 0;
	for (unsigned i = 0; i < size; ++i) {
		if (lastRow < controls[i]->getLastRow()) {
			lastRow = controls[i]->getLastRow();
		}
		if (lastCol < controls[i]->getLastCol()) {
			lastCol = controls[i]->getLastCol();
		}
	}
	++lastRow; ++lastCol;
}

unsigned Form::getControlCount() const { return size; }