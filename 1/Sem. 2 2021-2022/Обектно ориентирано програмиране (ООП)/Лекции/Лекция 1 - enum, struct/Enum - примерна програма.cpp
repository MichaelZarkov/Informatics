#include <iostream>

const int MAX = 30;

enum Colour
{
	UNDEFINED = -1,
	 
	 WHITE,
	 BLACK,
	 GREEN,

	COLOUR_COUNT
};

void printColour(Colour objectC) {
	std::cout << "The colour of the object is: ";

	switch (objectC) {
		case 0:
			std::cout << "white.\n";
			break;
		case 1:
			std::cout << "black.\n";
			break;
		case 2:
			std::cout << "green.\n";
			break;
		default:
			std::cout << "NO COLOUR!\n";
	}
}

Colour readColour() {
	char ch[MAX];
	std::cout << "Type a colour: ";
	std::cin.getline(ch, MAX);

	if (!strcmp(ch, "white"))	   return WHITE;
	else if (!strcmp(ch, "black")) return BLACK;
	else if (!strcmp(ch, "green")) return GREEN;
	else						   return UNDEFINED;
}

int main()
{
	Colour objectC = UNDEFINED;
	objectC = readColour();
	
	printColour(objectC);


	return 0;
}