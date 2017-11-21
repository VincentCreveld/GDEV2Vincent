#include <iostream>
#include "Parent.h"

Parent::Parent(string name) {
    this->name = name;
    string childName = "ChildOf" + name;
	
	child = std::make_unique<Child>(childName);
	
    //this->child = new Child(childName);
}

Parent::Parent(const std::shared_ptr<Parent> other) {
    cout << "Parent cctor" << endl;
	name = other->name;
	child = std::move(other->child);
    //this->child = new Child(*other.child);
}

Parent::~Parent() {
	child.release();
	cout << endl << "Killed off:" << name << endl;
    //delete this->child;
}

Parent& Parent::operator=(const std::shared_ptr<Parent> other) {
    cout << "Parent assignment" << endl;

    if (this == &(*other)) {
        return *this;
    }

    name = other->name;
    //delete this->child;
	child = std::move(other->child);
    //this->child = new Child(*other.child);

    return *this;
}

ostream& operator<<(ostream& os, const std::shared_ptr<Parent> parent) {
	os << "name: " << parent->name << " child: " << *parent->child;
    return os;
}
