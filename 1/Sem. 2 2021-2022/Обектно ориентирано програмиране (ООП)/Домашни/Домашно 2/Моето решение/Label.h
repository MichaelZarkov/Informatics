
#pragma once
#include "Control.h"

// Output controle.
class Label : public Control 
{
public:

	Label(const char* text, unsigned row, unsigned col);

	virtual ControlType getControlType() const override;

	virtual void changeText(const char*) override;
	virtual void consoleUserInput() override;			// Only input and IO controls.
	virtual void printUserInput() const override;       // Only input and IO controls.

	virtual Control* clone() const override;

	virtual void writeInPosition(char* page, unsigned columns) const override;
};

