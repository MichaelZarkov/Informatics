// Lesno domashno 8, zadacha 2

#include <iostream>

// Validates the number of rooms
size_t input_number_of_rooms() {
	size_t rooms;

	do {
		std::cout << "Number of rooms = ";
		std::cin >> rooms;
		if (rooms < 4 || rooms > 1024)
			std::cout << "Invalid number of rooms. Try again.\n";
	} while (rooms < 4 || rooms > 1024);
	
	return rooms;
}

// Validates the size of a room
bool check(int n) {
	// Check if the size of the room is in the range [2, 256]
	if (n < 2 || n > 256) {
		std::cout << "Invalid room size. Try again.\n";
		return true;
	}

	// Checks if the size of the room is a multiple of 2
	while (n != 2) {
		if (n % 2 == 0) {
			n /= 2;
		}
		else {
			std::cout << "Invalid room size. Not a power of 2. Try arain\n";
			return true;
		}
	}

	return false;
}

void input_array(int* array, size_t rooms) {
	for (size_t i = 0; i < rooms; ++i) {
		std::cout << "room " << i + 1 << " = ";
		bool a = true;
		
		do {
			std::cin >> array[i];
			a = check(array[i]);
		} while (a);
	}
	return;
}

// Prints the whole array in this format [a, b, c]
void print_array(int* array, size_t rooms) {
	std::cout << "[";
	for (size_t i = 0; i < rooms; ++i) {
		std::cout << array[i];
		if (i != rooms - 1)
			std::cout << ", ";
	}
	std::cout << "]\n";
	return;
}

// Command 'A'
int* add_troops(int* array, size_t rooms, size_t troops, size_t* prooms) {
	for (size_t i = 0; i < troops; i++)
	{
		size_t index = 0;		// Index of the biggest room

		// Finds the index of the biggest room
		for (size_t i = 1; i < rooms; ++i) {
			if (array[index] < array[i]) {
				index = i;
			}
		}

		// Checks if the biggest room is with size 2
		if (array[index] == 2) {
			std::cout << "Try again after Hoth.\n";
			break;
		}
		else {
			array[index] /= 2;
		}

		// Allocates a second array with size [rooms + 1]
		int* ar_1 = new(std::nothrow) int[rooms + 1];
		if (!ar_1) {
			std::cout << "Fail to allocate memory.\n";
			break;
		}

		// Writes the rooms to the newly allocted array
		// where the biggest room is split into 2 rooms
		for (size_t i = 0; i < rooms + 1; ++i) {
			if (i <= index) {
				ar_1[i] = array[i];
			}
			else if (i > index) {
				ar_1[i] = array[i - 1];
			}
		}
		
		delete[] array;		// Deletes the old array
		array = &ar_1[0];	// The new array is saved
		++rooms;
	}
	
	*prooms = rooms;
	return array;
}

int main()
{
	size_t rooms = input_number_of_rooms();
	int* array = new(std::nothrow) int[rooms];
	if (!array) {
		std::cout << "Fail to allocate memory.\n";
		return 1;
	}

	input_array(array, rooms);
	print_array(array, rooms);
	
	do {
		char c;
		std::cout << "\nChoose a command: ";
		std::cin >> c;

		switch (c) {
		
			// Command to add troops
		case 'A':			
			size_t troops;
			std::cin >> troops;
			array = add_troops(array, rooms, troops, &rooms);
			break;

		// Command to print the array
		case 'P':			
			print_array(array, rooms);
			break;
		
		// Command to close the program
		case 'E':
			std::cout << "Closing the program.";
			delete[] array;
			return 0;

		default:
			std::cout << "Invalid command. Try again.\n";
		}

	} while (true);
}