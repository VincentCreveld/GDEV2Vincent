#include "NPC.h"

#include "Specialization.h"
#include <vector>
#include <cstdarg>

std::vector<NPC*> npcVector;



void renderNPCS(std::vector<NPC *> npcV) {
	for (auto& npc : npcV) {
		std::cout << "------" << std::endl;
		npc->Render();
	}
	std::cout << "------" << std::endl;
}

int main() {
	
	npcVector.push_back(NPC::makeNPC("Pete", elf, shaman));
	npcVector.push_back(NPC::makeNPC("Will", elf, fighter));
	npcVector.push_back(NPC::makeNPC("Thrall", orc, shaman));
	npcVector.push_back(NPC::makeNPC("Henkie", elf, farmer));
	//npcVector.push_back(new Shaman(new Orc("Thrall")));
	//npcVector.push_back(new Farmer(new Soldier(new Shaman(new Orc("Absolute beast")))));
	//npcVector.push_back(new Shaman(new Farmer(new Soldier(new Elf("Absolute beast2")))));

	renderNPCS(npcVector);

	system("pause");
	return 0;
}
