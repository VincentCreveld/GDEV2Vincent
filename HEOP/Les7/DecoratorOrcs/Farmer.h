#pragma once
#include "Specialization.h"
class Farmer :
	public Specialization
{
public:
	Farmer(NPC* npc);
	void Render() override;
private:
	NPC* npc;
};

