
#pragma once
#include "Control.h"

// Формата НЕ проверява дали контролите се застъпват,
// нито при записването на контрола, нито при извеждането на формата.
class Form
{
public:

	Form();
	Form(const Form&);
	Form& operator=(const Form&);
	~Form();

	friend std::ostream& operator<<(std::ostream&, const Form&);  // Извеждане на формата на екрана.
	const Control* operator[](unsigned) const;                    // Оператор за индексиране.

	void addControl(const Control&);                     // Добавяне на контрола.
	void userInput() const;                              // Въвеждане на данни от потребителя за входните контроли.
	void changeText(const char*, unsigned controlID);    // Промяна на текста на посочена изходна контрола.
	void printInfoFromInputControls() const;             // Извежда в конзолата информацията от всички входни контроли.

	void rowsAndCols(unsigned& lastRow, unsigned& lastCol) const;    // Намира колко реда и колко колони е формата.

	unsigned getControlCount() const;

private:

	Control* operator[](unsigned);

	void free();
	void copy(const Form&);
	void resize();
	
private:
	
	Control** controls;
	unsigned size;
	unsigned capacity;
};

std::ostream& operator<<(std::ostream&, const Form&);  // Извеждане на формата на екрана.

