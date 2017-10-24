#include "Shaman.h"



Shaman::Shaman(NPC* npc) : Specialization(npc)
{
}

void Shaman::Render() {
	Specialization::Render();
	std::cout << "Shaman" << std::endl;
}
