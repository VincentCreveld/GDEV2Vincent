#pragma once
#include "NPC.h"
class Orc : public NPC
{
public:
	Orc(std::string name);
	void Render() override;
private:
	std::string name;
};

