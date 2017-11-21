#pragma once
#include "Specialization.h"
class Soldier :
	public Specialization
{
public:
	Soldier(NPC* npc);
	void Render() override;
private:
	NPC* npc;
};

