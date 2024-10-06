// Lesno domashno 7, zadacha 2

#include <iostream>
#include <cstdlib>
#include <ctime>

const int MAX = 52;

// Prints hole deck
void print_deck(int deck[MAX]) {
	for (int i = 0; i < 52; ++i) {		// Prints deck
		std::cout << deck[i] << "|";
	}
}



// Prints a specified element of a deck
void print_element(bool which_deck, int place, int deck[MAX]) {
		for (int i = 0; i < 52; ++i) {
			if (i == place) {
				std::cout << deck[place] << "|";
			}
			else {
				std::cout << "   |";
			}
		}
}



// Writes a sorted deck to 'deck[MAX]'
void generate_sorted_deck(int deck[MAX]) {
	int a = 0;
	for (int c = 2; c <= 14; ++c) {
		for (int s = 4; s >= 1; --s) {
			int b = c;
			if (c == 14) {
				b = 1;
			}
			deck[a] = 100 * s + b;
			++a;
		}
	}
}



// Prints the "visualisation" of the sorting of the cards
void print(int I, int place, int deck[MAX], int sorted_deck[MAX]) {
	/*	Step 11. Card...		1*
		   1|  2|  3|  4|		2*
		|402|302|202|102|		3* - whole deck in sorted form
		-----------------		4*
		|   |	|	|   |		5* - current element from the shuffled deck
		-----------------		6*
		|   |   |   |   |		7* - current element from the sorted deck
		-----------------		8*
	*/

	// Prints 1*
	std::cout << "\n\n\nStep " << I + 1 << ". Card from place " << I + 1 
			  << " in the shuffled deck, goes to place " << place + 1 
			  << " in the ordered deck.\n\n";								

	// Prints 2*
	for (int i = 0; i < 52; ++i) {			
		std::cout << " " << i + 1;
		if (i + 1 < 10) {
			std::cout << " |";
		}
		else {
			std::cout << "|";
		}
	}
	std::cout << "\n";

	// Prints 3*
	print_deck(sorted_deck);
	std::cout << "\n";

	// Prints 4*
	for (int i = 0; i < 13; ++i) {
		std::cout << "----------------";
	}
	std::cout << "\n";

	// Prints 5*
	print_element(false, I, deck);

	// Prints 6*
	std::cout << "\n";
	for (int i = 0; i < 13; ++i) {
		std::cout << "----------------";
	}
	std::cout << "\n";

	// Prints 7*
	print_element(true, place, sorted_deck);
	
	// Prints 8*
	std::cout << "\n";
	for (int i = 0; i < 52; ++i) {
		std::cout << "----";
	}
}



// Shuffles the deck and writes it to 'deck[MAX]'
void shuffle_deck(int deck[MAX]) {
	// Picks the places of 2 cards from the array at random
	// and switches their places.
	// Repeats 200 times.

	for (int i = 0; i < 200; ++i) {
		int n1 = rand() % 52;
		int n2 = rand() % 52;

		int a = deck[n1];
		deck[n1] = deck[n2];
		deck[n2] = a;
	}
}



// Sorts the shuffled 'deck[MAX]'
void sort_deck(int deck[MAX]) {
	int sorted_deck[MAX];				// Sorted deck. Not used in sorting. Only used for printing
	generate_sorted_deck(sorted_deck);

	/*  The sorting is done one value (card) at a time.
		The int values are taken from 'deck[]' in ascending order (from 0 to 51 inclusive)
		and the following formula is applied for each one, to determine the corresponding place
		of the value in the sorted deck.:
		
		place(in sorted deck) = (4 - suit) + (4 * (card - 2))
		
		"suit" is the hundred's digit of the int value [1, 4]
		"card" = value % 100 [1, 13]; when "card" = 1 it has to be changed to 14 for the formula to work
	
		 If the cards were encoded in a different way, this formula would not work.
	*/

	for (int i = 0; i < 52; ++i) {				// 'i' is the place of the  card in the shuffled deck
		int card_value;							// The number value of the card
			if (deck[i] % 100 == 1) {
				card_value = 14;				// Ace
			}
			else {
				card_value = deck[i] % 100;		// Every other card
			}
		
		int suit_value = deck[i] / 100;							// The number value of the suit
		int place = (4 * (card_value - 2)) + 4 - suit_value;	// The place of the card in the ordered deck 
		
		print(i, place, deck, sorted_deck);
	}

	return;
}


int main()
{
	srand(time(0));

	int deck[MAX];

	std::cout << "Type 0 to input a deck. Type any other number for random generated deck: ";
	int input;
	std::cin >> input;
	
	if (input) {
		generate_sorted_deck(deck);
		shuffle_deck(deck);
		std::cout << "\n\n\nShuffled deck:\n\n";
		print_deck(deck);
	}
	else {
		for (int i = 0; i < 52; ++i) {
			std::cout << "card[" << i + 1 << "] = ";
			std::cin >> deck[i];
		}
		std::cout << "\n\nYour deck:\n";
		print_deck(deck);
	}
	
	
	std::cout << "\n\n\nSorting step by step:";

	sort_deck(deck);
	return 0;
}