#pragma once

#include <string>
#include <iostream>
#include <memory>

using namespace std;

class Child {
    public:
        Child(string name);
        Child(const std::unique_ptr<Child> other);
		~Child();
    private:
        string name = "";

    public:
        friend ostream& operator<<(ostream& os, const Child child);
};

