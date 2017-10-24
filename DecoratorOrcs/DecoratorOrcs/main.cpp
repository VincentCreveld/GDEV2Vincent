#include "NPC.h"
#include "Elf.h"
#include "Orc.h"
#include "Shaman.h"
#include "Farmer.h"
#include "Soldier.h"
#include "Specialization.h"



int main() {
	NPC* soldierElf = new Soldier(new Elf("Pete"));
	NPC* shamanOrc = new Shaman(new Orc("Thrall"));
	NPC* farmerSoldierShamanOrc = new Farmer(new Soldier(new Shaman(new Orc("Absolute beast"))));
	NPC* shamanFarmerSoldierElf = new Shaman(new Farmer(new Soldier(new Elf("Absolute beast2"))));


	soldierElf->Render();
	shamanOrc->Render();
	farmerSoldierShamanOrc->Render();
	shamanFarmerSoldierElf->Render();

	system("pause");
	return 0;
}