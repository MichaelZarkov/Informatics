#pragma once
#include "Control.h"

// Input Control
class CheckBox : public Control
{
public:

	CheckBox(const char* text, unsigned row, unsigned col);

	virtual ControlType getControlType() const override;

	virtual void changeText(const char*) override;
	virtual void consoleUserInput() override;			// Only input and IO controls.
	virtual void printUserInput() const override;       // Only input and IO controls.

	virtual Control* clone() const override;

	// Записва контролата на определената и позиция.
	virtual void writeInPosition(char* page, unsigned columns) const override;

private:

	bool isChecked;
};

