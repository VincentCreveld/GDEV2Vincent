#include "Specialization.h"

Specialization::Specialization(NPC * npc) : npc(npc)
{
}

void Specialization::Render() {
	npc->Render();
}