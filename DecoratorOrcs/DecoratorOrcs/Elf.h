#pragma once
#include "NPC.h"
class Elf : public NPC
{
public:
	Elf(std::string name);
	void Render() override;
private:
	std::string name;
};

