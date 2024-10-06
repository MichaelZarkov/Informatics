
#pragma once
#include "Control.h"

class TextBox : public Control
{
public:
	
	TextBox(char const* text, unsigned posRow, unsigned posCol, unsigned height, unsigned width);

	virtual ControlType getControlType() const override;

	virtual void changeText(const char*) override;
	virtual void consoleUserInput() override;
	virtual void printUserInput() const override;       // Only input and IO controls.

	virtual Control* clone() const override;

	virtual void writeInPosition(char* page, unsigned columns) const override;

private:

	static unsigned const BUFF_SIZE;
};

