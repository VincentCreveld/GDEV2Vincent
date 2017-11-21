#include "Module.h"

int main() {
	Student* vincent = new Student("Vincent");
	Student* sten = new Student("Sten");
	Student* segri = new Student("Segri");
	Student* frank = new Student("Frank");
	Student* boella = new Student("Boella");
	Student* jurgen = new Student("Jurgen");
	Student* wessel = new Student("Wessel");
	Student* pim = new Student("Pim");
	Student* victor = new Student("Victor");
	Student* daan = new Student("Daan");

	Docent* edwin = new Docent("Edwin");
	Docent* valentijn = new Docent("Valentijn");
	Docent* simon = new Docent("Simon");

	Module* ecttp = new Module("Empowering Creative Thinking Through Programming", 4);
	Module* bpw = new Module("Building Playful Worlds", 2);
	Module* heop = new Module("Heavy Object Oriented Programming", 3);

	Student* studentArray[10] = { vincent, sten, segri, frank, boella, jurgen, wessel, pim, victor, daan };

	ecttp->addDocent(*simon);
	ecttp->addDocent(*valentijn);
	bpw->addDocent(*valentijn);
	heop->addDocent(*edwin);

	//Assign students to modules
	for (int i = 0; i < 10; i++)
	{
		//std::cout << studentArray[i]->getName() << studentArray[i]->getECs() << std::endl;
		if (i < 5) {
			heop->addStudent(studentArray[i]);
			//std::cout << studentArray[i]->getName() << studentArray[i]->getECs() << std::endl;
		}
		if (i < 8) {
			bpw->addStudent(studentArray[i]);
			//std::cout << studentArray[i]->getName() << studentArray[i]->getECs() << std::endl;
		}
		//std::cout << studentArray[i]->getName() << studentArray[i]->getECs() << std::endl;
		ecttp->addStudent(studentArray[i]);
	}
	
	//List all modules
	std::cout << std::endl;
	heop->listModule();
	std::cout << std::endl;
	bpw->listModule();
	std::cout << std::endl;
	ecttp->listModule();
	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << "Amount of ECs on " << studentArray[i]->getName() << ": " << studentArray[i]->getECs() << std::endl;
	}
	std::cout << std::endl;
	//Modify ECs
	heop->modifyECs(6);
	std::cout << "Amount of ECs on " << vincent->getName() << ": " << vincent->getECs() << std::endl;
	std::cout << std::endl;
	//Remove student
	heop->removeStudent(frank);
	std::cout << std::endl;
	//Reprint module
	heop->listModule();

	

	system("pause");
	return 0;
}