#include <iostream>
#include "Parent.h"

using namespace std;

int main() {
	{
	std::shared_ptr<Parent> p1 = std::make_shared<Parent>("Parent1");
	//Parent* p1 = new Parent("Parent1");
	cout << "P1:" << p1 << endl;
	cout << "P1Sharecount:" << p1.use_count() << endl;

	std::shared_ptr<Parent> p2 = p1; // roept de copy constructor aan
	cout << "P2:" << p2 << endl;
	cout << "P1Sharecount:" << p1.use_count() << endl;

	std::shared_ptr<Parent> p3 = std::make_shared<Parent>("Parent3");
	cout << "P3:" << p3 << endl;
	cout << "P1Sharecount:" << p1.use_count() << endl;

	p3 = p1; // roept de assignment operator aan
	cout << "P3:" << p3 << endl;
	cout << "P1Sharecount:" << p1.use_count() << endl;
	}
	/*
    delete p1;
    delete p2;
    delete p3;
	*/

	system("pause");
    return 0;
}