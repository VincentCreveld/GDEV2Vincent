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
	renderNPCS(npcVector);

	std::string nameString;
	std::string raceString;
	std::string typeString;
	NPCRaces tempRace;
	NPCTypes tempType;

	makeCharacter:
		std::cout << "Do you want to create an elf or orc?" << std::endl;
	retryName:
		std::cin >> raceString;
	if (raceString == "orc") {
		tempRace = orc;
	}
	else if (raceString == "elf") {
		tempRace = elf;
	}
	else{
		std::cout << std::endl << "That race doesn't exist in this world! Please enter if you are creating an elf or an orc." << std::endl;
		goto retryName;
	}

	std::cout << "Is your " << raceString << " a farmer, shaman or soldier?" << std::endl;
	retryJob:
		std::cin >> typeString;

	if (typeString == "shaman") {
		tempType = shaman;
	}
	else if (typeString == "farmer") {
		tempType = farmer;
	}
	else if (typeString == "soldier") {
		tempType = fighter;
	}
	else {
		std::cout << std::endl << "That profession doesn't exist in this world! Please enter if your " << raceString << " is a farmer, shaman or soldier." << std::endl;
		goto retryJob;
	}
	std::cout << "What is your " << typeString << " " << raceString << "'s name?" << std::endl;
	std::cin >> nameString;
	
	std::cout << "Character created!" << std::endl;

	npcVector.push_back(NPC::makeNPC(nameString, tempRace, tempType));
	renderNPCS(npcVector);

	goto makeCharacter;

	system("pause");
	return 0;
}
