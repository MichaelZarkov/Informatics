#pragma once
#include "String.h"

enum class ControlType {
	UNDEF = -1,
	
	InputControl,
	OutputControl,
	IOControl,
	
	END
};

class Control
{
protected:

	struct OrderedPair {
		unsigned int x, y;

		OrderedPair(unsigned x, unsigned y) {
			this->x = x;
			this->y = y;
		}
	};

	String text;
	OrderedPair position;		// Първата координата е редът, втората е колоната.
	OrderedPair size;			// Първата координата е броят редове, които заема, втората е броят колони.
	const unsigned int id;

	static unsigned int NEXT_ID;	// Може би да го преименувам на по-удачно?

public:

	Control(const char* text, unsigned row, unsigned col, unsigned height, unsigned width);
	Control(const Control&);
	virtual ~Control();

	virtual ControlType getControlType() const = 0;

	virtual void changeText(const char*) = 0;
	virtual void consoleUserInput() = 0;			// Only input and IO controls.
	virtual void printUserInput() const = 0;

	virtual Control* clone() const = 0;

	virtual void writeInPosition(char* page, unsigned columns) const = 0;  // Записва контролата на определената и позиция.

	unsigned getID() const;
	unsigned getFirstRow() const;
	unsigned getLastRow() const;
	unsigned getFirstCol() const;
	unsigned getLastCol() const;

};

