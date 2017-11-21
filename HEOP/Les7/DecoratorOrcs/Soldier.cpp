#include "Soldier.h"



Soldier::Soldier(NPC* npc) : Specialization(npc)
{
}

void Soldier::Render() {
	Specialization::Render();
	std::cout << "Soldier" << std::endl;
}
