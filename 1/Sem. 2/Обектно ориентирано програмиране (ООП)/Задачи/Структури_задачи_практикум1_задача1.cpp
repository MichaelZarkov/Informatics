// Strukturi - zadachi - praktikum 1
// zadacha 1

/*								Task info 

	Make a programe which holds in an array the data for a group of students:
	- First name
	- Last name
	- Faculty number (6 digits)
	- grades for 5 subjects
	
	and does the following operations:
	- adds data to the array for a new student (console input)
	- outputs to the console the names and grades of students born in a said month
	- outputs to the console the name of the student with the highest average grade

*/

#include <iostream>

const size_t numGr = 5;		// Number of grades in the 'grades' array
const size_t numStud = 20;	// How many students can be stored


struct Student {
	char firstName[20];
	char lastName[20];
	int facultyNum;
	long long EGN;
	double grades[numGr];
};


void highestAverageGrade(Student* studAr, size_t place) {
	std::cout << "\n----------------\nStudent with the highest average grade.\n";

	// First student is set as the one with highest average grade
	size_t stud = 0;
	double average = 0;
	for (size_t j = 0; j < numGr; ++j)
		average += studAr[0].grades[j];

	// Go through all the students
	for (size_t i = 1; i < place; ++i) {
		double currentAverage = 0;
		for (size_t j = 0; j < numGr; ++j)
			currentAverage += studAr[i].grades[j];

		if (currentAverage > average) {
			average = currentAverage;
			stud = i;
		}
	}

	std::cout << "\nName: " << studAr[stud].firstName << " " << studAr[stud].lastName
			  << "\nAverage grade: " << average / numGr
			  << "\n----------------\n";
}


// Outputs the names of students and their average grade born in a given month
void studentGradesBornInMonth(Student* studAr, size_t place) {
	std::cout << "\n----------------\nAverage grade of students born in a chosen month.\n";
	if (!place) {
		std::cout << "\nNo students in the array.\n----------------\n";
		return;
	}
	
	int month;			// Which month
	// Check if it is a month
	do {
		std::cout << "\nMonth: ";
		std::cin >> month;
		if (month < 1 || month > 12)
			std::cout << "\nNot a month! Try again.\n";
	} while (month < 1 || month > 12);

	// Go through all the students
	for (size_t i = 0; i < place; ++i) {
		if ((studAr[i].EGN / 1000000) % 100 == month) {
			std::cout << "\nName: " << studAr[i].firstName << " " << studAr[i].lastName;

			double average = 0;
			for (size_t j = 0; j < numGr; ++j)
				average += studAr[i].grades[j];

			std::cout << "\nAverage grade: " << average / numGr << std::endl;
		}
	}

	std::cout << "\n----------------\n";
}


// Console input for a student
void addStudent(Student &stud) {
	std::cout << "\n----------------\nAdd a student.\n";
	std::cout << "\nFirst name: ";
	std::cin >> stud.firstName;
	std::cout << "Last name: ";
	std::cin >> stud.lastName;
	
	do {
		std::cout << "Faculty number: ";
		std::cin >> stud.facultyNum;

		if (stud.facultyNum / 100000 != 0)
			std::cout << "\nFaculty number can not be greater than '99 999'. Try again.\n";

	} while (stud.facultyNum / 100000 != 0);
	
	std::cout << "EGN: ";
	std::cin >> stud.EGN;

	std::cout << "Grades (" << numGr << " in total):\n";
	for (size_t i = 0; i < numGr; ++i) {
		std::cout << i + 1 << ": ";
		std::cin >> stud.grades[i];
	}

	std::cout << "\n----------------\n";
}


int main()
{
	// Allocate array for the students
	Student* studAr = new(std::nothrow) Student[numStud];
	if (!studAr) {
		std::cout << "\nFail to allocate memory for the array of students.\n";
		return 1;
	}

	// Operations available
	std::cout << "For adding a student, type '0'.\nFor average grades of the students born in a particular month, type '1'."
			  << "\nFor the studen with the highest average score, type '2'."
			  << "\nFor closing the program, type '-1'\n";

	size_t place = 0;		// Places ocupied in 'studAr[]'

	while (true) {
		std::cout << "\nChoose an operation: ";
		int operation;										// Which operation
		std::cin >> operation;

		
		switch (operation) {
		case -1:
			break;
		case 0:
			if (operation < numStud) {
				addStudent(studAr[place]);
				++place;
			}
			else
				std::cout << "\nThe array for students is full. Can't add more.\n";
			break;

		case 1:
			studentGradesBornInMonth(studAr, place);
			break;

		case 2:
			highestAverageGrade(studAr, place);
			break;

		default:
			std::cout << "\nNot a valid operation! Try again.\n";
			break;
		}


		// Shuts down the program 
		if (operation == -1) {
			delete[] studAr;
			break;
		}
	}
}

