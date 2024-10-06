/*
	Задача 3.
	
	а) Създайте следните типове:

	Apartment - собственик, адрес, наемател, цена на наема и информация за това дали в момента е нает апартамента
	Address - държава, град, улица и номер на улицата
	Person - име, години, цвят на очите и косата
	
	б) Да се реализират следните функции за работа с типовете дефинирани от потребителя:

	*четене на данните от стандартния вход
	*отпечатване на данните на стандартния изход
	да се провери дали апартамента е даден под наем
	да се даде под наем апартаментът, ако е свободен
	*да се продаде апартамента на нов собственик
	създайте масив от апартаменти и по подаден наем да се намери апартамент на наемателя
*/



#include <iostream>
#include <cstring>

const int NUMBER_OF_APARTMENTS = 3;
const int STR_LEN = 32;
const char* COLOUR_NAMES[]{ "white", "green", "blue", "brown" };
enum Colour { UNDEFINED = -1, WHITE, GREEN, BLUE, BROWN, C_COUNT };

struct Person {
	int age = -1;
	Colour eyes = Colour::UNDEFINED;
	Colour hair = Colour::UNDEFINED;
	char name[STR_LEN]{ "Undefined" };
};

struct Address {
	int streetNum = -1;
	char street[STR_LEN] { "Undefined" };
	char city[STR_LEN]	 { "Undefined" };
	char country[STR_LEN]{ "Undefined" };
};

struct Apartment {
	double rentPrice = -1.0;
	Address address;
	Person owner;
	Person occupant;
	bool isOccupied{ false };
};

void printPerson(const Person& p) {
	std::cout << "\n  |Name: " << p.name
		<< "\n  |Age: " << p.age;

	std::cout << "\n  |Hair colour: ";
	if (UNDEFINED < p.hair && p.hair < C_COUNT)
		std::cout << COLOUR_NAMES[p.hair];
	else
		std::cout << "undefined";

	std::cout << "\n  |Eye colour: ";
	if (UNDEFINED < p.eyes && p.eyes < C_COUNT)
		std::cout << COLOUR_NAMES[p.eyes];
	else
		std::cout << "undefined";
}

// DOES NOT CHECK IF n >= numOfAprts or 0 > n!!!
void printAprt(const Apartment* aprts) {
	std::cout << "\nPrint apartment.\nType the array number of the apartment: ";
	int n;
	std::cin >> n;
	std::cin.get();
	std::cout << "Apartment details.\n";
	std::cout << "Owner:";
	printPerson(aprts[n].owner);
	std::cout << "\nAdress:" 
		<< "\n  |Country: " << aprts[n].address.country 
		<< "\n  |City: " << aprts[n].address.city
		<< "\n  |Street: " << aprts[n].address.street
		<< "\n  |Street number: " << aprts[n].address.streetNum << std::endl;
	
	if (aprts[n].isOccupied) {
		std::cout << "Occupant:";
		printPerson(aprts[n].occupant);
	}
	else
		std::cout << "Not occupied at the moment.\n";
	
	std::cout << "\nRent price: " << aprts[n].rentPrice << "lv.\n";
}

Colour readColour() {
	char ch[STR_LEN];
	std::cin.getline(ch, STR_LEN);

	if (!strcmp(ch, "white"))	   return WHITE;
	else if (!strcmp(ch, "green")) return GREEN;
	else if (!strcmp(ch, "blue"))  return BLUE;
	else if (!strcmp(ch, "brown")) return BROWN;
	else						   return UNDEFINED;
}

void readPerson(Person& p) {
	std::cout << "  |Name: ";
	std::cin.getline(p.name, STR_LEN);
	std::cout << "  |Age: ";
	std::cin >> p.age;
	std::cin.get();
	std::cout << "  |Hair colour: ";
	p.hair = readColour();
	std::cout << "  |Eye colour: ";
	p.eyes = readColour();
}

void readAddress(Address& ad) {
	std::cout << "  |Country: ";
	std::cin.getline(ad.country, STR_LEN);
	std::cout << "  |City: ";
	std::cin.getline(ad.city, STR_LEN);
	std::cout << "  |Street: ";
	std::cin.getline(ad.street, STR_LEN);
	std::cout << "  |Street number: ";
	std::cin >> ad.streetNum;
	std::cin.get();
}

// Reads an array of Apartments
void readAprts(Apartment* aprt, const int numOfAprts) {
	for (int i = 0; i < numOfAprts; ++i) {
		std::cout << "\nEnter apartment " << i + 1 << " details\n";
		std::cout << "Owner datails\n";
		readPerson(aprt[i].owner);
		std::cout << "Address\n";
		readAddress(aprt[i].address);
		std::cout << "Occupant\n";
		readPerson(aprt[i].occupant);
		aprt[i].isOccupied = true;
		std::cout << "Price: ";
		std::cin >> aprt[i].rentPrice;
		std::cin.get();
	}
	std::cout << "Details saved.\n";
}

// DOES NOT CHECK IF n >= numOfAprts or 0 > n!!!
void changeOwner(Apartment* aprts) {
	std::cout << "\nSell apartment.\nType the array number of the apartment: ";
	int n;
	std::cin >> n;
	std::cout << "Current owner: " << aprts[n].owner.name
		<< "\nEnter new owner:\n";
	std::cin.get();
	readPerson(aprts[n].owner);
	std::cout << "Details saved.\n";
}

int main()
{
	Apartment* aprts = new(std::nothrow) Apartment[NUMBER_OF_APARTMENTS];
	if (!aprts) { std::cout << "Programme crashed!\nClosing...\n"; return 1; }

	
	//printAprt(*aprts);

	while (true) {
		std::cout << "\nType 'write' to input apartment details,"
			<< "\n     'sell' to change owner,"
			<< "\n     'rent' to rent the aprt if its free,"
			<< "\n     'check' to check if its occupied,"
			<< "\n     'find' to find available apartment at given price,"
			<< "\n     'print' to print the details for an apartment,"
			<< "\n     'close' to close the programme.\n";

		char ch[STR_LEN];
		std::cin.getline(ch, STR_LEN);
		
		if (!strcmp(ch, "write")) { 
			readAprts(aprts, NUMBER_OF_APARTMENTS);
		}
		else if (!strcmp(ch, "sell")) {
			changeOwner(aprts);
		}
		else if (!strcmp(ch, "rent")) {
			// to be written
		}
		else if (!strcmp(ch, "check")) {
			// to be written
		}
		else if (!strcmp(ch, "find")) {
			// to be written
		}
		else if (!strcmp(ch, "print")) {
			printAprt(aprts);
		}
		else if (!strcmp(ch, "close"))
			break;
		else
			std::cout << "\nInvalid command! Try again.\n";
	}

	delete[] aprts;
	std::cout << "\n\nProgramme closed.\n";

	return 0;
}