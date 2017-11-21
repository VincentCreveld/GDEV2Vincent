#include "Child.h"

Child::Child(string name) {
    this->name = name;
}

Child::Child(const std::unique_ptr<Child> other) {
    this->name = other->name;
}

Child::~Child()
{
	cout << endl << "Killed off:" << name << endl;
}

//ostream& operator<<(ostream& os, const std::unique_ptr<Child> child) {

ostream& operator<<(ostream& os, const Child child) {
    os << "name: " << child.name;
    return os;
}

