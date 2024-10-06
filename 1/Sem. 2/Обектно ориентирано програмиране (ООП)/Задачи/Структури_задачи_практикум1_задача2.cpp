// Strukturi - zadachi - praktikum 1
// zadacha 2

/*										  Task info 

	Make a "struct" 'Point' which contains 2 coordinates of a Cartesian coordinate system (dekartova).
	Make the following functions for point manipulation:
	- Read point coordinates from console
	- Print point coordinates to the console
	- Find the distance of a point to the origin
	- Find the distance between 2 points

*/

#include <iostream>

const size_t numPts = 20;		// How many points in the array

// Coordinates of a point
struct Point {
	double x;
	double y;
};

void distanceBetween2Points(Point* pts, size_t place) {
	std::cout << "\n---------------\nFinds the diatance between 2 points.\n";
	if (!place) {
		std::cout << "\nNo points in the array.\n---------------\n";
		return;
	}

	std::cout << "\nPoints are in the range [1, " << place << "].\nType a number not in the range to leave.\n";

	// Finds the distance
	size_t i, j;
	do {
		std::cout << "\nFirst point: ";
		std::cin >> i;
		--i;

		// If not in range then leave
		if (i < 0 || i >= place)
			break;

		std::cout << "\nSecond point: ";
		std::cin >> j;
		--j;

		// If not in range then leave
		if (j < 0 || j >= place)
			break;

		double x, y;
		// Difference of the 'x' coordinates of the points
		if (pts[i].x > pts[j].x)
			x = pts[i].x - pts[j].x;
		else
			x = pts[j].x - pts[i].x;

		// Difference of the 'y' coordinates of the points
		if (pts[i].y > pts[j].y)
			y = pts[i].y - pts[j].y;
		else
			y = pts[j].y - pts[i].y;

		// Output distance
		std::cout << "\nDistance = " << sqrt((x * x) + (y * y)) << std::endl;
	} while (true);

	std::cout << "\nLeaving...\n---------------\n";
}

// Finds the distance of a point to the origin
void distanceToTheOrigin(Point* pts, size_t place) {
	std::cout << "\n---------------\nFinds the distance of a point to the origin.\n";
	if (!place) {
		std::cout << "\nNo points in the array.\n---------------\n";
		return;
	}

	std::cout << "\nPoints are in the range [1, " << place << "].\nType a number not in the range to leave.\n";

	// Find the distance
	size_t i;			// Which point
	do {
		std::cout << "\nPoint ";
		std::cin >> i;
		--i;

		if (i < 0 || i >= place) {
			std::cout << "\nLeaving...\n---------------\n";
			return;
		}
		else {
			double r = (pts[i].x * pts[i].x) + (pts[i].y * pts[i].y);
			std::cout << "Distance = " << sqrt(r) << std::endl;
		}
	} while (true);
}

// Outputs to the console the coordinates of the "i-th" point in the array of points
void printCoordinates(Point* pts, size_t place) {
	std::cout << "\n---------------\nPrint coordinates of a point.\n";
	
	// Return if no points in the array
	if (!place) {
		std::cout << "\nNo points in the array.\n---------------\n";
			return;
	}

	std::cout << "\nPoints are in the range [1, " << place << "].\nType a number not in the range to leave.\n";

	// Prints the coordinates
	size_t i;						// Which point
	do {
		std::cout << "\nPoint ";
		std::cin >> i;
		--i;

		if (i < 0 || i >= place) {
			std::cout << "\nLeaving...\n---------------\n";
			return;
		}
		else
			std::cout << "(" << pts[i].x << ", " << pts[i].y << ")";
		
	} while (true);
}

// Console input for the coordinates of a point
void inputPoint(Point& pt) {
	std::cout << "\n---------------\nInput a point.\n"
		<< "\nX = ";
	std::cin >> pt.x;
	std::cout << "Y = ";
	std::cin >> pt.y;
	
	std::cout << "---------------\n";
}

int main()
{
	// Allocate the array for points
	Point* pts = new(std::nothrow) Point[numPts];
	if (!pts) {
		std::cout << "\nFail to allocate memory for the points array!\n";
		return 1;
	}

	// Operations available
	std::cout << "For inputing point coordinates, type '0'."
		<< "\nFor printing point coordinates, type '1'."
		<< "\nFor finding the distance to the origin (0, 0), type '2'."
		<< "\nFor distance between 2 points, type '3'."
		<< "\nFor closing the program, type '-1'.\n";
			  
	size_t place = 0;

	while (true) {
		std::cout << "\n\nChoose an operation: ";
		int operation;										// Which operation
		std::cin >> operation;
		std::cout << std::endl;

		switch (operation) {
		case -1:
			break;
		case 0:
			if (place < numPts) {
				inputPoint(pts[place]);
				++place;
			}
			else
				std::cout << "\nThe array for points is full. You can not add more points.";
			break;

		case 1:
			printCoordinates(pts, place);
			break;

		case 2:
			distanceToTheOrigin(pts, place);
			break;

		case 3:
			distanceBetween2Points(pts, place);
			break;

		default:
			std::cout << "\nNot a valid operation! Try again.\n";
			break;
		}


		// Shuts down the program 
		if (operation == -1) {
			delete[] pts;
			break;
		}
	}
}