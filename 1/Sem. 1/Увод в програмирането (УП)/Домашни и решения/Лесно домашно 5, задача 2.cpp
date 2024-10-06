// Lesno domashno 5, zadacha 2 (Mario)

#include <iostream>
#include <cstdlib>
#include <ctime>

// Finds the best starting position for the run with the most steps and the number of steps 
bool startPosition_1(bool track[], unsigned length) {
	unsigned pos1 = 0, pos2 = 0;
	unsigned len1 = 0, len2 = 0;
	unsigned zero = 0;

	for (unsigned i = 0; i < length; ++i) {

		if (track[i]) {
			++len2;
			len2 += zero;
			zero = 0;
		}
		else if (i == 0 && !track[0]) {
			while (!track[i] && i < length) {
				++i;
			}
			pos2 = i;
			--i;
		}
		else {
			++zero;
			if (zero > 3) {
				if (len1 < len2) {
					len1 = len2;
					pos1 = pos2;
				}
				len2 = 0;
				while (!track[i] && i < length) {
					if (track[i + 1]) {
						pos2 = i + 1;
					}
					++i;
				}
				--i;
				zero = 0;
			}
		}
	}
	if (len1 < len2) {
		len1 = len2;
		pos1 = pos2;
	}
	
	if (len1 != 0) {
		std::cout << "\nBest starting position is " << pos1 << " and the run length is " << len1 << " steps.\n";
		return true;
	}
	else {
		std::cout << "\nThis level is only void. It doesn't have platforms.\n";
		return false;
	}
}



// Finds the length and start position of the longest platform
void longestPlatform_2(bool track[], unsigned length) {

	unsigned steps1 = 0, steps2 = 0;
	unsigned pos1 = 0, pos2 = 0;

	for (unsigned i = 0; i < length; ++i) {
		if (track[i]) {
			++steps2;
		}
		else {
			if (steps2 > steps1) {
				steps1 = steps2;
				pos1 = pos2;
			}
			steps2 = 0;
			pos2 = i + 1;
		}
	}
	if (steps2 > steps1) {
		steps1 = steps2;
		pos1 = pos2;
	}
	
	std::cout << "The longest platform starts from position " << pos1 << " and has a length of " << steps1 << " steps.\n"; 
	return;
}



// Checks if a platform is with prime length (called in 'void primePlatforms_3()')
bool checkPrime(unsigned platformLength) {
	if (platformLength == 2) {
		return true;
	}
	if (platformLength < 2 || platformLength % 2 == 0) {
		return false;
	}

	for (unsigned div = 3; div * div <= platformLength; div += 2) {
		if (platformLength % div == 0) {
			return false;
		}
	}
	return true;
}



// Finds the number of prime-length platforms and their lengths
void primePlatforms_3(bool track[], unsigned length) {

	unsigned count = 0;					// Number of prime platforms
	unsigned platformLength = 0;		// Current platform length
	unsigned primeLengths[3333];		// Array for storing the lengths of the platforms (in a track there can be at most 3333 prime-langth platforms)
	track[length] = 0;					// Indicates the end of the track


	for (unsigned i = 0; i <= length; ++i) {		// '<=' because 'track[length] = 0' indicates the end of the track
		if (track[i]) {
			++platformLength;
		}
		else {
			if (checkPrime(platformLength)) {
				primeLengths[count] = platformLength;
				++count;
			}
			platformLength = 0;
		}
	}
	
	if (count != 0) {
		std::cout << "There are " << count << " prime-length platforms. Their lengths are:";
		for (unsigned i = 0; i < count; ++i) {
			std::cout << " " << primeLengths[i];
		}
		std::cout << ".\n";
	}
	else {
		std::cout << "There are 0 prime-length platforms.\n";
	}
	return;
}



// Finds the length of the added platforms needed for Mario to complete the track
void addingPlatforms_4(bool track[], unsigned length) {
	unsigned startPosition = 0;
	for (unsigned i = 0; i < length; ++i) {
		if (track[i]) {
			startPosition = i;
			break;
		}
	}

	unsigned count = 0;			// Number of platforms added
	unsigned gapLength = 0;		// Length of the current gap
	track[length] = 1;			// Indicates the end of the track

	for (unsigned i = startPosition; i <= length; ++i) {		// '<=' because 'track[length] = 1' indicates the end of the track
		if (!track[i]) {
			++gapLength;
		}
		else {
			if (i != length) {
				count += gapLength / 4;
				gapLength = 0;
			}
			else {
				count += gapLength / 4;
				if (gapLength % 4 != 0) {
					++count;
				}
			}
		}
	}
	
	std::cout << "Mario needs " << count << " new platforms with total length " << count << "\n";
	return;
}



int main()
{
	bool track[10001];		// The last position in the array is used for indicator for the end of the track
	int length;
	std::cout << "Enter track length: ";
	std::cin >> length;

	if (length > 0) {			// User defined track
		std::cout << "Enter track sequence: ";
			for (int i = 0; i < length; ++i) {
				std::cin >> track[i];
			}
	}
	else if (length == 0) {		// Built in track
		length = 20;
		const bool default_track[20] = { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0 };
		
		std::cout << "Built in track:\n";
		
		for (int i = 0; i < 20; ++i) {
			std::cout << default_track[i] << " ";
			track[i] = default_track[i];
		}
	}
	else {						// Random track
		srand(time(0) + length);		// Seed = computer time + the input for track length
		length = (rand() % 9990) + 10;	// Generates random length
		
		std::cout << "Random track with length " << length << ":\n";
		
		for (int i = 0; i < length; ++i) {	// Generates random track
			track[i] = rand() % 2;
			std::cout << track[i] << " ";
		}
	}
	std::cout << "\n";

	if (startPosition_1(track, length)) {		// If tha track is only zeros, the other 3 functions ar not called
		
		longestPlatform_2(track, length);
		primePlatforms_3(track, length);
		addingPlatforms_4(track, length);
	}
	return 0;
}