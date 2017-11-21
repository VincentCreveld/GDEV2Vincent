#include "Orc.h"

Orc::Orc(std::string name) : name(name) {
}

void Orc::Render(){
		std::cout << "Orc: " << name << std::endl;
}

