
#include "Control.h"

unsigned Control::NEXT_ID = 0;

Control::Control(const char* text, unsigned row, unsigned col, unsigned height, unsigned width)
	: text(text), position(row, col), size(height, width), id(NEXT_ID)
{
	++NEXT_ID;
}
// Предефинирам копиращия конструктор,
// защото генерираният от компилатора прави "this->id = other.id",
// а трябва всеки обект да е с различен идентификатор.
Control::Control(const Control& other)
	: text(other.text), position(other.position), size(other.size), id(NEXT_ID)
{
	++NEXT_ID;
}
Control::~Control() {
	if (id + 1 == NEXT_ID)
		--NEXT_ID;
}

unsigned Control::getID() const       { return id; }
unsigned Control::getFirstRow() const { return position.x; }
unsigned Control::getLastRow() const  { return position.x + size.x - 1; }
unsigned Control::getFirstCol() const { return position.y; }
unsigned Control::getLastCol() const  { return position.y + size.y - 1; }
