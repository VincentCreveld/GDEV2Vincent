#include "Farmer.h"

Farmer::Farmer(NPC* npc) : Specialization(npc)
{
}

void Farmer::Render() {
	Specialization::Render();
	std::cout << "Farmer" << std::endl;
}
