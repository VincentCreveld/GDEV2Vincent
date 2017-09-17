#include "Student.h"
#include <iostream>

Student::Student(std::string name) {
	this->name = name;
	ECs = 0;
}

std::string Student::getName() {
	return name;
}

int Student::getECs() {
	return ECs;
}

void Student::addECs(int ecs) {
	ECs += ecs;
}

void Student::subtractECs(int ecs) {
	ECs -= ecs;
}


