// Strukturi - zadachi - praktikum 1
// zadacha 3

/*										  Task info 

	Make "Library" struct which contains a list of books (n <= 1000).
	For every book save its title, author and ISBN (international standart book number).
	Make the following functions:
	- Add a book to the library from the console (save the title, author, ISBN)
	- Remuve a book by given ISBN
	- Print the number of books in the library

*/

#include <iostream>
#pragma warning(disable : 4996)

const size_t numBooks = 10;		// How many books in the Library
const size_t tLen = 30;		// Max char length for the title of the book
const size_t nLen = 30;		// Max char length for the author's name

// Library. Contains the name of the title and the author of a book and ISBN number of the book
struct Library {
	
	char title[numBooks][tLen];
	char author[numBooks][nLen];
	long long isbn[numBooks];			// International Standard Book Number
	size_t bookNum = 0;					// Number of books added
};

// Prints a line
const char* prtLine() {
	return "\n---------------\n";
}

// Remuve a book with a given ISBN
void removeBookByISBN(Library& lib) {
	std::cout << prtLine() << "Remove a book by ISBN.\n\n";
	if (!lib.bookNum) {
		std::cout << "No books it the library!" << prtLine();
		return;
	}

	long long a;
	std::cout << "ISBN: ";
	std::cin >> a;

	for (size_t i = 0; i < lib.bookNum; ++i) {
		if (a == lib.isbn[i]) {
			--lib.bookNum;
			
			// Copy the data of the last book in 'lib' to the place of the deleted book
			lib.isbn[i] = lib.isbn[lib.bookNum];
			strcpy(lib.title[i], lib.title[lib.bookNum]);
			strcpy(lib.author[i], lib.author[lib.bookNum]);

			std::cout << "\nBook deleted." << prtLine();
			return;
		}
	}
}

// Add a book from the console (done by pointers)					!!! UNFINISHED !!!
//void addBook(Library* lib) {
//	std::cout << "\n---------------\nAdd a book.\n\nBook title: ";
//	std::cin >> (*lib).title[(*lib).bookNum];
//	std::cout << "Author: ";
//	std::cin >> (*lib).author[(*lib).bookNum];
//	std::cout << "ISBN: ";
//	std::cin >> (*lib).isbn[(*lib).bookNum];
//	
//	++(*lib).bookNum;
//
//	std::cout << "\nFinished adding.\n---------------\n";
//}

// Add a book from the console (done by reference)
void addBook(Library& lib) {
	std::cout << prtLine() << "Add a book.\n\n";
	
	if (lib.bookNum >= numBooks) {
		std::cout << "The library is full!" << prtLine();
		return;
	}


	bool same;
	do {
		std::cout << "ISBN: ";
		std::cin >> lib.isbn[lib.bookNum];

		// Check if a book has the same ISBN
		same = false;
		for (size_t i = 0; i < lib.bookNum; ++i) {
			if (lib.isbn[lib.bookNum] == lib.isbn[i]) {
				same = true;
				std::cout << "There is already a book with this ISBN! Try again.\n";
			}
		}
	} while (same);

	
	std::cout << "Book title: ";
	std::cin >> lib.title[lib.bookNum];
	std::cout << "Author: ";
	std::cin >> lib.author[lib.bookNum];
	
	
	++lib.bookNum;

	std::cout << "\nFinished adding." << prtLine();
}

// Print the data for a particular book or for all the books
void printBookData(Library& lib) {
	std::cout << prtLine() << "Print book data.\n\n";
	if (!lib.bookNum) {
		std::cout << "No books it the library!" << prtLine();
		return;
	}

	std::cout << "To print a particular book, type 0."
		<< "\nTo print all books, type any other number: ";
	
	size_t a;		// Single or all books
	std::cin >> a;
	
	// Print single book
	if (!a) {
		std::cout << "\nWhich book: ";
		std::cin >> a;			// Which book

		if (a >= lib.bookNum || a < 0) {
			std::cout << "Invalid book number!" << prtLine();
			return;
		}
		
		std::cout << "Author: " << lib.author[a] << "		Title: '" << lib.title[a] << "'		ISBN: " << lib.isbn[a] << prtLine();
		return;
	}

	// Print all books
	std::cout << "\nNumber of books in the library: " << lib.bookNum << std::endl;
	for (size_t i = 0; i < lib.bookNum; ++i)
		std::cout << "\nBook " << i << "#  -  Author: " << lib.author[i] << "		Title: '" << lib.title[i] << "'		ISBN: " << lib.isbn[i];
	std::cout << prtLine();
}

int main()
{
	Library* lib = new(std::nothrow) Library;
	if (!lib) {
		std::cout << "\nFail to allocate memory for 'lib'!";
		return 1;
	}

	// Operations available
	std::cout << "To add a book, type '0'."
		<< "\nTo remove a book, type '1'."
		<< "\nTo print the number of books and all the their data, type '2'."
		<< "\nTo close the program, type '-1'.\n";

	while (true) {
		std::cout << "\n\nChoose an operation: ";
		int operation;										// Which operation
		std::cin >> operation;
		std::cout << std::endl;

		switch (operation) {
		case -1:
			delete lib;
			return 0;

		case 0:
			//addBook(lib);			// Done with pointers
			addBook(*lib);
			break;

		case 1:
			removeBookByISBN(*lib);
			break;

		case 2:
			printBookData(*lib);
			break;

		default:
			std::cout << "\nNot a valid operation! Try again.\n";
			break;
		}
	}
}