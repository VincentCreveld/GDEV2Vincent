#pragma once
#include <string>
#include <iostream>


enum NPCTypes {
	farmer, shaman, fighter
};
enum NPCRaces {
	orc, elf
};

class NPC
{
public:
	virtual void Render() = 0;
	static NPC* makeNPC(std::string name, NPCRaces race, NPCTypes t1);
};