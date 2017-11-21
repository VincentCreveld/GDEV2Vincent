#pragma once

#include <string>
#include <ostream>

#include "Child.h"

using namespace std;

class Parent {
    public:
        Parent(string name);

        Parent(const std::shared_ptr<Parent> other);

        virtual ~Parent();

        Parent& operator=(const std::shared_ptr<Parent> other);

        friend ostream& operator<<(ostream& os, const std::shared_ptr<Parent> parent);

    private:
        string name;
		std::unique_ptr<Child> child;
        //Child* child;
};

