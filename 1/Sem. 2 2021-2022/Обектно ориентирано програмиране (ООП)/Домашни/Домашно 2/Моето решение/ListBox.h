
#pragma once
#include "RadioButton.h"

// Input control.
class ListBox : public Control
{
public:

	ListBox(char const*, unsigned row, unsigned col);
	ListBox(const ListBox&);
	~ListBox();

	virtual ControlType getControlType() const override;

	virtual void changeText(const char*) override;
	virtual void consoleUserInput() override;			// Only input and IO controls.
	virtual void printUserInput() const override;

	virtual Control* clone() const override;

	virtual void writeInPosition(char* page, unsigned columns) const override;  // Записва контролата на определената и позиция.

private:

	void copy(const ListBox&);
	void free();

private:
	
	String* options;
	unsigned selectedOption;    // Избира се точно една. Не може нищо да не е избрано. Започват от нула.
	unsigned optionCount;
};

