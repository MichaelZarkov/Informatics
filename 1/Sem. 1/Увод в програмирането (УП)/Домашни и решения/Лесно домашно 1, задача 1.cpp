/*  Lesno Domashno 1
	
	Zadacha 1

	A program which takes 6 whole numbers - the x, y coordinates of the centers
	of 2 circles and their radii - and outputs their position in respect to one another:
	- the circles intersect.
	- the circles do not intersect.
	- the circles are tangent.*/


#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	// Number input
	int x1, y1, r1, x2, y2, r2;
		cout << "\nInput the coordinates of the center of the first circle (x1, y1) and its radius (r1):" << endl << "x1 y1 r1 = ";
		cin >> x1 >> y1 >> r1;
		
		cout << "\nInput the coordinates of the center of the second circle (x2, y2) and its radius (r2):" << endl << "x2 y2 r2 = ";
		cin >> x2 >> y2 >> r2;


		if ((x1 == x2) && (y1 == y2) && (r1 == r2))
		{
			cout << "\nCircles overlap.\n";
			return 0;
		}


		unsigned int c = ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));	 // Distance between the two centers squared
		unsigned int R = (r1 + r2) * (r1 + r2);								// Sum of the radii squared
			
			if (c - R > 0)
			{
				cout << "\nThe circles do not intersect.\n";
			}
			else
			{
				if (c - R < 0)	// The smaller circle is inside the biger one
				{
					
					unsigned int H = (r1 - r2) * (r1 - r2);	// The difference of the radii squared

					if (c > H)
					{
						cout << "\nThe circles intersect.\n";
					}
					else
					{
						if (c < H)
						{
							cout << "\nThe circles do not intersect.\n";
						}
						else
						{
							cout << "\nThe circles are tangent.\n";
						}
					}
				}
				else
				{
					cout << "\nThe circles are tangent.\n";
				}
			}
		return 0;
}