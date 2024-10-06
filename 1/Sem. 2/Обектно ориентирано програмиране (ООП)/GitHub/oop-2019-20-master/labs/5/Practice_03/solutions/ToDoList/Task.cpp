#include <iostream>
#include <cstring>
#include "Task.h"

using std::cout;
using std::endl;

Task::Task() {
    strcpy(this->title, "");
    strcpy(this->description, "");
}

Task::operator=(Task task) {
    strcpy(this->title, task.getTitle());
    strcpy(this->description, task.getDescription());
}

Task::Task(char* title, char* description) {
    strcpy(this->title, title);
    strcpy(this->description, description);
}

const char* Task::getTitle() {
    return title;
}

const char* Task::getDescription() {
    return description;
}

void Task::printInfo(){
    cout << title << "(" << description << ")" << endl;
}

