#include "NPC.h"
#include "Elf.h"
#include "Orc.h"
#include "Shaman.h"
#include "Farmer.h"
#include "Soldier.h"



NPC* NPC::makeNPC(std::string name, NPCRaces race, NPCTypes t1) {
	NPC* tempNPC;
	va_list args;
	switch (race)
	{
	case orc:
		tempNPC = new Orc(name);
		break;
	case elf:
		tempNPC = new Elf(name);
		break;
	default:
		tempNPC = new Orc("NO_NAME_ENTERED");
		break;
	}

	switch (t1)
	{
	case farmer:
		tempNPC = new Farmer(tempNPC);
		break;
	case shaman:
		tempNPC = new Shaman(tempNPC);
		break;
	case fighter:
		tempNPC = new Soldier(tempNPC);
		break;
	default:
		break;
	}

	return tempNPC;
};
