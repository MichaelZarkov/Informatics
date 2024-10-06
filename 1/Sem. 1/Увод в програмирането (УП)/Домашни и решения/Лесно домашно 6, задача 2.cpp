// Lesno domashno 6, zadacha 2

#include <iostream>
#include <cstdlib>
#include <ctime>

const int MAX = 9;

unsigned inputSizeOfField() {
	int N;
	do {
		std::cout << "Size of the field [3, 9]\nN = ";
		std::cin >> N;
	} while (N < 3 || N > MAX);
	return N;
}

unsigned inputGameMode() {
	int mode;
	std::cout << "Choose game mode: 1 - PvP, 2 - PvC, 3 - CvC\n";
	do {
		std::cout << "Mode: ";
		std::cin >> mode;
	} while (mode < 1 || mode > 3);
	
	std::cout << "\n";
	return mode;
}




// For a person. Inputs and validates coordinates and writes to 'matrix[][]'
void inputCoordinates(int i, int N, int matrix[][MAX]) {
	int R, C;				// Coordinates: R-row, C-column
	if (i % 2 == 0) {		// Which player's turn is it
		std::cout << "Its player 1's turn: ";
	}
	else {
		std::cout << "Its player 2's turn: ";
	}

	// Validates the coordinates
	do {
		std::cin >> R >> C;
		int a = R - C;
		if (R - C > 0) {
			a *= -1;
		}

		if (R < 1 || R > N || C < 1 || C > N) {
			std::cout << "Invalid coordinates, try again: ";
		}
		else {
			if (matrix[R - 1][C - 1] != -1) {
				std::cout << "Already occupied space, try again: ";
			}
			else {
				break;
			}
		}
	} while (1);
	
	if (i % 2 == 0) {
		matrix[R - 1][C - 1] = 1;	// Player 1 'X'
	}
	else {
		matrix[R - 1][C - 1] = 0;	// Player 2 'O'
	}
}

// For the computer. Inputs and validates coordinates and writes to 'matrix[][]'
void computerCoordinates(int N, int matrix[][MAX]) {
	srand(time(0));
	int R, C;
	std::cout << "Player 2's (computer) turn:\n";

	do {
		R = (rand() % N) + 1;
		C = (rand() % N) + 1;
		
		if (matrix[R - 1][C - 1] == -1) {
			break;
		}
	} while (1);
	
	matrix[R - 1][C - 1] = 0;
}

// Prints the current state of the playing field
void print(int N, int matrix[][MAX]) {
	for (int R = 0; R < N; ++R) {		
		for (int C = 0; C < N; ++C) {
			std::cout << "[";
			
			if (matrix[R][C] == -1) {
				std::cout << " ";
			}
			else if (matrix[R][C] == 0) {
				std::cout << "O";
			}
			else {
				std::cout << "X";
			}
			std::cout << "]";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

// Checks if there is a winning position on the playing field
bool checkForWin(int N, int matrix[][MAX]) {
	// Checks the rows
	for (int R = 0; R < N; ++R) {
		bool a = true;
		for (int C = 0; C < N; ++C) {
			if (matrix[R][C] == -1 || matrix[R][0] != matrix[R][C]) {
				a = false;
				break;
			}
		}
		
		if (a) {
			std::cout << "Player ";
			if (matrix[R][0]) {
				std::cout << 1;
			}
			else {
				std::cout << 2;
			}
			std::cout << " wins.\n";
			return true;
		}
	}

	// Checks the columns
	for (int C = 0; C < N; ++C) {
		bool a = true;
		for (int R = 0; R < N; ++R) {
			if (matrix[R][C] == -1 || matrix[0][C] != matrix[R][C]) {
				a = false;
				break;
			}
		}

		if (a) {
			std::cout << "Player ";
			if (matrix[0][C]) {
				std::cout << 1;
			}
			else {
				std::cout << 2;
			}
			std::cout << " wins.\n";
			return true;
		}
	}
	
	// Checks the main diagonal
	bool a = true;
	for (int i = 0; i < N; ++i) {
		if (matrix[i][i] == -1 || matrix[0][0] != matrix[i][i]) {
			a = false;
			break;
		}
	}
	if (a) {
		std::cout << "Player ";
		if (matrix[0][0]) {
			std::cout << 1;
		}
		else {
			std::cout << 2;
		}
		std::cout << " wins.\n";
		return true;
	}

	// Checks the second diagonal
	a = true;
	for (int i = 0; i < N; ++i) {
		if (matrix[i][N - (i + 1)] == -1 || matrix[0][N - 1] != matrix[i][N - (i + 1)]) {
			a = false;
			break;
		}
	}
	if (a) {
		std::cout << "Player ";
		if (matrix[0][N - 1]) {
			std::cout << 1;
		}
		else {
			std::cout << 2;
		}
		std::cout << " wins.\n";
		return true;
	}
	
	return false;
}




// PvP mode
void gameMode1(int N, int matrix[][MAX]) {
	std::cout << "PvP mode\n";
	for (int i = 0; i < N * N; ++i) {		// If the places on the field run out that means the game is a draw
		inputCoordinates(i, N, matrix);
		print(N, matrix);
		if (checkForWin(N, matrix)) {
			return;
		}
	}
	std::cout << "The game is a draw.\n";
	return;
}

// PvC mode
void gameMode2(unsigned N, int matrix[][MAX]) {
	std::cout << "PvC mode\n";
	for (int i = 0; i < N * N; ++i) {		// If the places on the field run out that means the game is a draw
		if (i % 2 == 0) {
			inputCoordinates(i, N, matrix);
		}
		else {
			computerCoordinates(N, matrix);
		}

		print(N, matrix);
		if (checkForWin(N, matrix)) {
			return;
		}
	}
	std::cout << "The game is a draw.\n";
}

// CvC mode
void gameMode3(unsigned N, int matrix[][MAX]) {
	std::cout << "Not available yet.";
	return;
}




int main()
{
	int N = inputSizeOfField();	// Size of the field
	int mode = inputGameMode();	// Game Mode
	int matrix[MAX][MAX];				// The values in the matrix can be '1', '0' or '-1'
										// '1' means there is 'X'; '0' = 'O'; '-1' = empty space (unoccupied by 'O' or 'X')

	// Sets the values in the matrix to '-1' (empty field)
	for (int R = 0; R < N; ++R) {
		for (int C = 0; C < N; ++C) {
			matrix[R][C] = -1;
		}
	}

	switch (mode){
	case 1:
		gameMode1(N, matrix);	// PvP
		break;
	case 2:
		gameMode2(N, matrix);	// PvC
		break;
	case 3:
		gameMode3(N, matrix);	// CvC
		break;
	}
	return 0;
}