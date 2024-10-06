#include <iostream>
#include <cstring>

struct Point {
    double x, y;
} p, q;
Point r;

const int MAX_NAME = 3;

struct Student {
    char name[MAX_NAME];
    int fn;
    double grade;
};

void printStudent(Student const& s) {
    std::cout << "Name: \t" << s.name << std::endl
        << "Faculty number: \t" << s.fn << std::endl
        << "Grade: \t" << s.grade << std::endl;
    // !!! s.grade--;
}

void printStudentRow(Student const& s) {
    std::cout << "| ";
    std::cout.setf(std::ios::left);
    std::cout.width(30);
    std::cout << s.name;
    std::cout << "| ";
    std::cout.setf(std::ios::left);
    std::cout.width(8);
    std::cout << s.fn;
    std::cout << "| ";
    std::cout.width(5);
    std::cout.setf(std::ios::fixed);
    std::cout.precision(2);
    std::cout << s.grade;
    std::cout << "|" << std::endl;
}


void readStudent(Student& s) {
    std::cerr << "Enter name: ";
    std::cin.getline(s.name, MAX_NAME);
    std::cerr << "Enter faculty number: ";
    std::cin >> s.fn;
    std::cerr << "Enter grade: ";
    std::cin >> s.grade;
}

//void testStruct() {
//    std::cout << "sizeof(Point) = " << sizeof(Point) << std::endl;
//    std::cout << "sizeof(Student) = " << sizeof(Student) << std::endl;
//    Point p = { 1.2, 3.4 }, q;
//    q = p;
//    Student s = { "Ivan Kolev", 40000, 5.75 };
//    printStudent(s);
//    readStudent(s);
//    printStudent(s);
//    // !!! q = s;
//    // !!! s = q;
//    // !!! std::cout << s;
//    // !!! std::cin >> s;
//    Student* ps1 = &s;
//    strcpy(ps1->name, "Peter Petrov");
//    std::cout << ps1->name << std::endl;
//}

unsigned readStudents(Student students[]) {
    unsigned n;
    std::cerr << "Enter number of students: ";
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin.get(); // изчистваме символа за нов ред
        std::cerr << "Please, enter student  " << i + 1 << "." << std::endl;
        readStudent(students[i]);
    }
    return n;
}

void printStudents(Student students[], unsigned n) {
    for (int i = 0; i < n; i++) {
        // std::cout << "Студент " << i + 1 << ":" << std::endl;
        printStudentRow(students[i]);
    }
}

double findAverageGrade(Student students[], unsigned n) {
    double s = 0;
    for (int i = 0; i < n; i++)
        s += students[i].grade;
    return s / n;
}

void sortStudents(Student students[], unsigned n) {
    for (int i = 0; i < n - 1; i++) {
        int mini = i;
        for (int j = i + 1; j < n; j++)
            if (students[j].fn < students[mini].fn)
                mini = j;
        Student tmp = students[mini];
        students[mini] = students[i];
        students[i] = tmp;
    }
}

void testStudents() {
    const int MAX_STUDENTS = 3;
    Student students[MAX_STUDENTS];
    unsigned n = readStudents(students);
    printStudents(students, n);
    sortStudents(students, n);
    printStudents(students, n);
    std::cout << "Average grade: " << findAverageGrade(students, n) << std::endl;
}

int main(int, char**) {
    // testStruct();
    testStudents();
    return 0;
}