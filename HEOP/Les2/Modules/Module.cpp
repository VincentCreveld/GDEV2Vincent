#include "Module.h"

Module::Module(std::string name, int ecs) {
	ECs = ecs;
	this->name = name;
}

std::string Module::getName() {
	return name;
}

void Module::listModule() {
	std::vector<Docent>::iterator it = docenten.begin();
	std::vector<Student*>::iterator it2 = students.begin();

	std::cout << "Module: " << getName() << std::endl;
	std::cout << "-------------" << std::endl;
	std::cout << "Docent(en):" << std::endl;
	while (it != docenten.end()) {
		std::cout << it->getName() << std::endl;
		it++;
	}
	std::cout << "-------------" << std::endl;
	std::cout << "ECs: " << getECs() << std::endl;
	std::cout << "-------------" << std::endl;
	std::cout << "Studenten:" << std::endl;
	while (it2 != students.end()) {
		std::cout << (*it2)->getName() << std::endl;
		it2++;
	}
	std::cout << "-------------" << std::endl;
}

int Module::getECs() { 
	return ECs;
}
void Module::modifyECs(int ecs) {
	std::cout << "ECs for " << getName() << " got changed from " << ECs << " to " << ecs << "." << std::endl;

	std::vector<Student*>::iterator it = students.begin();
	while (it != students.end()) {
		(*it)->subtractECs(ECs);
		(*it)->addECs(ecs);

		std::cout << "Changed " << (*it)->getName() << " ECs from " << ((*it)->getECs() - ecs + ECs) << " to " << ((*it)->getECs()) << "." << std::endl;
		it++;
	}
	ECs = ecs;
}


void Module::removeStudent(Student* student) {
	std::vector<Student*>::iterator it = students.begin();
	while (it != students.end()) {
		if ((*it)->getName() == student->getName()) {
			std::cout << (*it)->getName() << " got removed from "<< getName() << std::endl;
			(*it)->subtractECs(ECs);
			it = students.erase(it);
		}
		else {
			it++;
		}
	}
}

void Module::addStudent(Student* student) {
	student->addECs(ECs);
	students.push_back(student);
	std::cout << "Added " << student->getName() << " to " << getName() << std::endl;
}

void Module::removeDocent(Docent docent) {
	std::vector<Docent>::iterator it = docenten.begin();
	while (it != docenten.end()) {
		if (it->getName() == docent.getName()) {
			std::cout << it->getName() << " got removed from " << getName() << std::endl;
			it = docenten.erase(it);
		}
		else {
			it++;
		}
	}
}

void Module::addDocent(Docent docent) {
	docenten.push_back(docent);
	std::cout << "Added " << docent.getName() << " to " << getName() << std::endl;
}