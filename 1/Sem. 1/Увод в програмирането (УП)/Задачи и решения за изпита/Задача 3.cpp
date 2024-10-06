#include <iostream>

/*	Task 3	*/

// Tests: 4 5 1 0 0 1 -1 0 0 -1 0 0 1 2 0 1 0 2 1 -2 0 1 0 -2 1

	 
struct bench {
	double x, y;
	bool lit = false;	// is the bench lit from a lamp
};

struct lamp {
	double x, y, r;
};


// Reads from the keyboard the number of benches and number of lamps.
void InputNum(int& numberOfBenches, int& numberOfLamps) {
	do {
		std::cout << "Number of benches: ";
		std::cin >> numberOfBenches;
		if (numberOfBenches < 0) {
			std::cout << "You can not have negative number of benches! Try again.\n";
		}
	} while (numberOfBenches < 0);

	std::cout << "\n";

	do {
		std::cout << "Number of lamps: ";
		std::cin >> numberOfLamps;
		if (numberOfLamps < 0) {
			std::cout << "You can not have negative number of lapms! Try again.\n";
		}
	} while (numberOfLamps < 0);

	return;
}

void InputCoordinates(bench* benches, lamp* lamps, const int Bnum, const int Lnum) {

	std::cout << "\nInput bench x, y:\n";
	for (int i = 0; i < Bnum; ++i) {
		std::cout << i + 1 << ": ";
		std::cin >> benches[i].x >> benches[i].y;
	}

	std::cout << "\nInput lamp x, y, r:\n";
	for (int i = 0; i < Lnum; ++i) {
		std::cout << i + 1 << ": ";
		std::cin >> lamps[i].x >> lamps[i].y >> lamps[i].r;
	}

	return;
}

// Returns true if the plan meets the requirements.
bool IsPlanOK(bench* bn, lamp* lm, const int Bnum, const int Lnum) {
	
	// Loop through every lamp.
	for (int i = 0; i < Lnum; ++i) {	// should try this with pointer arithmetics
		double r = lm[i].r * lm[i].r;

		// Loop through every bench.
		for (int j = 0; j < Bnum; ++j) {
			double dx = lm[i].x - bn[j].x, dy = lm[i].y - bn[j].y;	// Calculate the difference of the 'x' and 'y' coordinates of a lamp and a bench (we don't care if they are negative because we square them below).
			double R = (dx * dx) + (dy * dy);						// Calculate square of the distance between the lamp and the bench.
			
			if (R <= r)		// If the distance is smaller than the radius of the lamps - mark the lamp as lit.
				bn[j].lit = true;
		}
	}

	// Check if all benches are lit.
	for (int i = 0; i < Bnum; ++i) {
		if (!bn[i].lit)		// if there is a not lit bench 
			return false;
	}

	return true;
}

// Returns true if every bench is lit.
bool IsItLit(bench* bn, lamp* lm, int* combination, const int k, const int Bnum, const int Lnum, const double r) {

	// Set every bench to not lit.
	for (int i = 0; i < Bnum; ++i)
		bn[i].lit = false;

	for (int i = 0; i < Lnum; ++i) {
		// Is the lamp in the combination
		bool in_combination = false;
		for (int p = 0; p < k; ++p) {
			if (i == combination[p]) {
				in_combination = true;
			}
		}

		// If the index of the lamp is in the combination do not use the lamp.
		if (!in_combination){
			for (int j = 0; j < Bnum; ++j) {
			double dx = lm[i].x - bn[j].x, dy = lm[i].y - bn[j].y;
			double R = (dx * dx) + (dy * dy);
			if (R <= r)
				bn[j].lit = true;
			}
		}
	}

	for (int i = 0; i < Bnum; ++i) {
		if (!bn[i].lit)
			return false;
	}

	return true;
}

int rec(int* array, int k, int n) {
	++array[k];
	if (array[k] == n) {
		if (k == 0) {
			return n + 1;
		}
		array[k] = rec(array, k - 1, n - 1) + 1;
	}

	return array[k];
}

// Returns the number of benches that can be removed without leaving an unlit bench.
int RemoveLamps(bench* bn, lamp* lm, int* combination, const int Bnum, const int Lnum) {

	// If only one lamp
	if (Lnum == 1)
		return 0;

	// Find the smallest lamp radius.
	double min = lm[0].r;
	for (int i = 1; i < Lnum; ++i) {
		if (lm[i].r < min)
			min = lm[i].r;
	}

	// Check if there is a combination of 'k' indexes of lamps that meet the requirements of the project.
	// If there is such combination then try 'k+1'.
	// 'n' - number of elements,
	// 'k' - number of places.

	int n = Lnum;
	int k = 1;
	for (; k < n; ++k) {
		bool valid = false;		// Is there a combination with 'k' places that meets the requirements

		// Make initial combination
		for (int j = 0; j < k; ++j)
			combination[j] = j;

		// Go through the other combinations with 'k' places
		for (int i = k; i < n; ++i) {
			
			// Check if valid
			if (IsItLit(bn, lm, combination, k, Bnum, Lnum, min)) {
				valid = true;
				break;
			}
			
			combination[k - 1] = i;		// make another combination

			// Check if valid
			if (IsItLit(bn, lm, combination, k, Bnum, Lnum, min)) {
				valid = true;
				break;
			}
			
			i = rec(combination, k - 1, n) - 1;		// make another combination
		}

		// Return if no combination with 'k' places meets the requirements
		if (!valid)
			return k - 1;
	}

	return k - 1;
}

void Delete(bench* benches, lamp* lamps, int* combination) {
	if (benches)
		delete[] benches;

	if (lamps)
		delete[] lamps;

	if (combination)
		delete[] combination;

	return;
}

int main()
{
	int Bnum;	// number of benches
	int Lnum;	// number of lamps
	InputNum(Bnum, Lnum);

	// Deals with the cases when the number of benches or lamps is zero.
	if (Bnum == 0) {
		std::cout << "\nEvery bench will be lit. The plan meets the requirements."
				<< "\nThe number of lamps that can be removed is " << Lnum << ".\n";
		return 0;
	}
	if (Lnum == 0) {
		std::cout << "\nThe plan does not meet the requirements.\n";
		return 0;
	}

	// Allocate memory for the arrays of benches, lamps and combinations.
	bench* benches = nullptr;
	lamp* lamps = nullptr;
	int* combination = nullptr;
	benches = new(std::nothrow) bench[Bnum];
	if (!benches) {
		std::cout << "\nFail to allocate memory!\n";
		return 1;
	}
	lamps = new(std::nothrow) lamp[Lnum];
	if (!lamps) {
		Delete(benches, lamps, combination);
		std::cout << "\nFail to allocate memory!\n";
		return 1;
	}
	combination = new(std::nothrow) int[Lnum];
	if (!combination) {
		Delete(benches, lamps, combination);
		std::cout << "\nFail to allocate memory!\n";
		return 1;
	}


	InputCoordinates(benches, lamps, Bnum, Lnum);
	bool Lit = IsPlanOK(benches, lamps, Bnum, Lnum);		// If the requirements of the project are met Lit = true.

	// If the plan is OK, check how many lamps can be removed.
	int number_of_removed_lamps;
	if (Lit) {
		number_of_removed_lamps = RemoveLamps(benches, lamps, combination, Bnum, Lnum);
	}

	// Print the result.
	if (Lit) {
		std::cout << "\nEvery bench will be lit. The plan meets the requirements."
			<< "\nThe number of lamps that can be removed is " << number_of_removed_lamps << ".\n";
	}
	else {
		std::cout << "\nThe plan does not meet the requirements\n";
	}

	Delete(benches, lamps, combination);
	return 0;
}