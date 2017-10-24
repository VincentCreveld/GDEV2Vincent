#include "Elf.h"

Elf::Elf(std::string name) : name(name) {
}

void Elf::Render() {
	std::cout << "Elf: " << name << std::endl;
}
