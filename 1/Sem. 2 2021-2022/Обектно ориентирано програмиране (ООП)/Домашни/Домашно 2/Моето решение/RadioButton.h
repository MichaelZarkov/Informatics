
#pragma once
#include "Control.h"

// Input control.
class RadioButton : public Control
{
public:

	RadioButton(char const* options, unsigned row, unsigned col);

	virtual ControlType getControlType() const override;

	virtual void changeText(const char*) override;
	virtual void consoleUserInput() override;			// Only input and IO controls.
	virtual void printUserInput() const override;       // Only input and IO controls.

	virtual Control* clone() const override;

	// Записва контролата на определената и позиция.
	virtual void writeInPosition(char* page, unsigned columns) const override;

private:

	void writeTheOptions(char const*, unsigned);

private:

	unsigned selectedOption;    // Ако е нула, то никоя опция не е избрана.
	// Броят на опциите е същият като броя на редовете.
};

