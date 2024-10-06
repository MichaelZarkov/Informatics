// Bonus zadachi 2, zadacha 5
// Analise and do statistics with "FMI Vault" card numbers
// For more info check the files 'Lesno domashno 1' and 'Lesno domashno 2'

#include <iostream>
#include <ctime>
#include <cstdlib>

using std::cout;
using std::nothrow;
using std::cin;
using std::endl;

// Validates the input for the card count
size_t input() {
	int count;
	do {
		cout << "Card count = ";
		cin >> count;

		if (count < 1) cout << "Count must be bigger than zero. Try again.\n";

	} while (count < 1);

	return count;
}

// Writes consecutive numbers to 'allCards'. Not essential to the programe (just for fun)
void inputConsecGen(int* allCards, size_t count) {
	for (int i = 0; i < count; ++i) {
		allCards[i] = i;
	}
}

// Inputs randomly generated card numbers
void randInput(int* allCards, size_t count) {
	for (size_t i = 0; i < count; ++i) {
		allCards[i] = rand() * rand();
	}
}

// Keyboard input for the card numbers in the array
void inputCards(int* allCards, size_t count) {
	for (size_t i = 0; i < count; ++i) {
		// Validates if the card number is bigger than 0
		do {
			cout << "a[" << i + 1 << "] = ";
			cin >> allCards[i];
			
			if (allCards[i] < 1)
			cout << "Card number must be bigger than 0. Try again.\n";

		} while (allCards[i] < 1);
	}
}

// Prints the number of valid and invalid cards
// Writes in 'spec[]' how many cards for each specialty
void sortCards(int* allCards, size_t count, size_t* spec) {
	int validCards = 0;		// Number of valid cards

	for (size_t i = 0; i < count; ++i) {
		int dig3 = (allCards[i] / 1000000) % 10;		// Specialty digit
		
		// For more info for the validation process
		// check the files 'Lesno domashno 1' and 'Lesno domashno 2'
		if (allCards[i] > 999999999 || allCards[i] < 100000000 || 
			dig3 == 9 || dig3 == 7 || 
			(allCards[i] / 10000000) % 10 > 7 ||
			(allCards[i] % 1000000) / 10 == 0) {

			allCards[i] = -1;
			continue;
		}

		// Step 1
		unsigned oddSum = 0, evenSum = 0;
		unsigned num = allCards[i];

		for (int j = 0; j < 9; ++j) {
			if (j % 2 == 0) {
				evenSum += num % 10;
			}
			else {
				oddSum += num % 10;
			}
			num /= 10;
		}
		num = oddSum * evenSum;

		// Step 2
		int dig2 = (allCards[i] / 10000000) % 10;
		if (dig2 < 2)
			num |= 0xbabe;
		else if (dig2 > 5)
			num |= 0xcafe;
		else
			num |= 0xc001;

		// Step 3
		if (dig2 % 2 == 0)
			num ^= 0xface;
		else
			num ^= 0xc0de;

		// Step 4
		int shifts = 0;
		oddSum = num;			// Just using the available variable. NO connection to the previous steps
		while (oddSum != 0) {
			oddSum >>= 1;
			++shifts;
		}
		
		if (shifts > 4) num >>= shifts - 4;
		if (num > 9) num %= 10;
		
		// If valid then ++apropriateSpecialty and '++validCards'
		if (num == allCards[i] % 10) {
			++validCards;
			if (dig3 == 8) 
				dig3 = 7;
			++spec[dig3];
		}
		else
			allCards[i] = -1;
	}

	cout << "\nNumber of valid cards = " << validCards << "\nNumber of invalid cards = " << count - validCards << endl;
}

// Deletes the 'specMatrix' up to a certain row ('i')
void deleteMatrix(size_t i, int** specMatrix) {
	for (size_t j = 0; j < i; ++j)
		delete[] specMatrix[j];
	delete[] specMatrix;
}

// Allocates array with apropriate size of each specialty
int** allocateMatrix(int* allCards, size_t* spec) {
	int** specMatrix = new(nothrow) int* [8];
	if (!specMatrix) {
		cout << "Fail to allocate memory.";
		return specMatrix;
	}

	for (size_t i = 0; i < 8; ++i) {
		specMatrix[i] = new(nothrow) int[spec[i]];
		if (!specMatrix) {
			deleteMatrix(i, specMatrix);
			delete[] specMatrix;
			return nullptr;
		}
	}
	return specMatrix;
}

// Writes all card numbers with a given specialty
// in the corresponding array for the specialty in 'specMatrix'
void writeToMatrix(int** specMatrix, int whichSpec, size_t count, int* allCards, size_t* spec) {
	size_t i = 0;
	
	// It is separated by "if" because there is no specialty with the number 7
	if (whichSpec == 7) {
		for (size_t j = 0; j < count; ++j) {
			if (allCards[j] > 0 && (allCards[j] / 1000000) % 10 == 8) {
				//if (i < spec[whichSpec]) {		// These are here if you don't trust that sufficient memory is allocated
					specMatrix[whichSpec][i] = allCards[j];
					++i;
				//}
			}
		}
	}
	else {
		for (size_t j = 0; j < count; ++j) {
			if (allCards[j] > 0 && (allCards[j] / 1000000) % 10 == whichSpec) {
				//if (i < spec[whichSpec]) {		// These are here if you don't trust that sufficient memory is allocated
					specMatrix[whichSpec][i] = allCards[j];
					++i;
				//}
			}
		}
	}
}

// Prints the matrix by specialties
void printMatrix(size_t* spec, int** specMatrix) {
	// Prints how many card numbers in each the specialty
	for (int i = 0; i < 8; ++i) {
		cout << "\nSpec " << i << ": " << spec[i];
	}

	// Prints all the card numbers in each specialty
	for (int i = 0; i < 8; ++i) {
		cout << endl << endl << "I = " << i << endl;
		for (size_t j = 0; j < spec[i]; ++j) {
			cout << specMatrix[i][j] << ", ";
		}
	}
}

//1. Prints the cuantity of cards for this specialty
//2. Biggest and smallest card number for the men and the women
//3. How many bly-eyed women
//4. How many dark-haired men
void specialtyStats(int** specMatrix, size_t* spec, int whichSpec) {
	// 1.
	cout << "\nAll cards: " << spec[whichSpec];

	// 2., 3. and 4.
	int wom_N = 0, man_N = 0, wom_B = 0, man_D = 0;				// 'wom_N'/'man_N' - highest card number for a woman/man (in a specialty)
																// 'wom_B'/'man_D' - count of women/men with blue eyes/dark hair (in a specialty)	
	for (size_t i = 0; i < spec[whichSpec]; ++i) {
		int dig2 = (specMatrix[whichSpec][i] / 10000000) % 10;	// Gender, eye colour and hair colour
		
		if (dig2 % 2 == 0) {							// Women
			if (specMatrix[whichSpec][i] > wom_N)
				wom_N = specMatrix[whichSpec][i];
			if (!dig2 || dig2 == 2)
				++wom_B;
		}
		else {											// Men
			if (specMatrix[whichSpec][i] > man_N)
				man_N = specMatrix[whichSpec][i];
			if (dig2 == 7 || dig2 == 3)
				++man_D;
		}
	}
	
	cout << "\nHighest card number for a woman: " << wom_N << "\nHighest card number for a man: " << man_N 
		 << "\nCount of women with blue eyes: " << wom_B << "\nCount of men with dark hair: " << man_D << "\n\n";
}

void allCardsStats(int** specMatrix, size_t* spec) {

}

int main()
{
	srand(time(0));

	size_t count = input();						// Card count
	int* allCards = new(nothrow) int[count];	// Array for the card numbers
	if (!allCards) {
		cout << "Fail to allocate memory for 'allCards'.\n";
		return 1;
	}


	// Chose between keyboard and 
	// random computer input for the card numbers
	bool CompOrPerson;
	cout << "Press '1' for random and '0' for keyboard input: ";
	cin >> CompOrPerson;
	if (CompOrPerson) {
		randInput(allCards, count);
		//inputConsecGen(allCards, count);
	}
	else {
		inputCards(allCards, count);
	}


	/* 0 - Informatics;
	   1 - Computer science;
	   2 - Information systems;
	   3 - Software engineering;
	   4 - Applied mathematics;
	   5 - Mathematics;
	   6 - Statistics;
	   7 - Mathematics and informatics*/
	size_t spec[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };	// Holds the number of cards for each specialty

	sortCards(allCards, count, spec);

	int** specMatrix = allocateMatrix(allCards, spec);
	if (!specMatrix) {
		cout << "\nFail to allocate memory for 'specMatrix'.\n";
		return 1;
	}

	for (int i = 0; i < 8; ++i) {
		writeToMatrix(specMatrix, i, count, allCards, spec);
	}
	
	delete[] allCards;

	//printMatrix(spec, specMatrix);

	for (int i = 0; i < 8; ++i) {
		switch (i) {
		case 0:
			cout << "\nInformatics - 0:";
 			break;
		case 1:
			cout << "\nComputer science - 1:";
			break;
		case 2:
			cout << "\nInformation systems - 2:";
			break;
		case 3:
			cout << "\nSoftware engeneering - 3:";
			break;
		case 4:
			cout << "\nApplied mathematics - 4:";
			break;
		case 5:
			cout << "\nMathematics - 5:";
			break;
		case 6:
			cout << "\nStatistics - 6:";
			break;
		case 7:
			cout << "\nMathematics and informatics - 7:";
		}
		specialtyStats(specMatrix, spec, i);
	}
	
}