#pragma once
#include "Docent.h"
#include "Student.h"
#include <string>
#include <vector>
#include <iostream>

class Module{
public:
	Module(std::string, int);
	void addStudent(Student*);
	void removeStudent(Student*);
	int getECs();
	void modifyECs(int);
	std::string getName();
	void addDocent(Docent);
	void removeDocent(Docent);
	void listModule();

private:
	std::vector<Student*> students;
	std::vector<Docent> docenten;
	int ECs;
	std::string name;
};

