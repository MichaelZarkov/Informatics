/*
 Object-Oriented Programming 2022 @ FMI
 Sample code for lecture #01

  Structures. Bit fields.
*/

#include <iostream>
using std::cout;
using std::endl;

#include "address.h"
#include "student.h"

// Print all the students from a given program.
// Demonstrates pointer to structure.
void printAllFromProgram(Program prg, Student* students, int cnt)
{
    cout << "==========================================\n";
    cout << "All for program " << prg << "\n";
    for (Student* iter = students; iter < students + cnt; ++iter) {
        if (iter->program == prg)
            printStudent(*iter);
    }
    cout << "==========================================" << endl;
}

int main()
{
   /* Address a;
    cout << sizeof(a) << endl;
    readAddress(a);
    printAddress(a);

    cout << sizeof(Student) << endl;*/


    const int NumStudents = 5;
    Student students[NumStudents];

    for (int i = 0; i < NumStudents; ++i) {
        students[i].name = nullptr;
        readStudent(students[i]);
    }

    for (int i = 0; i < NumStudents; ++i) {
        printStudent(students[i]);
    }

    for (int i = (int)PROGRAM_UNKNOWN; i < (int)PROGRAM_COUNT; ++i) {
        cout << "\n\n";
        printAllFromProgram((Program)i, students, NumStudents);
    }

    for (int i = 0; i < NumStudents; ++i) {
        clearStudentData(students[i]);
    }


    return 0;
}


/*
Pesho
Sofia
Something
1234
2
2444
1
1
1
1
y
n
Gosho
Sofia
Other
1234
3
289
2
2
1
1
y
n
Sasho
Varna
Bla-Bla Bla
1111
5
358
1
2
1
2
y
y
Ivan
Dobrich
Ulichka
9321
1
222
2
2
3
2
n
y
Dragan
Sofia
Wkushti 123
1432
1
321
1
1
1
2
n
n
*/
