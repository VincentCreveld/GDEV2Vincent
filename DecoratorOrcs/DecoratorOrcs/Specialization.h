#pragma once
#include "NPC.h"
class Specialization : public NPC
{
public:
	Specialization(NPC* npc);
	void Render() override;
private:
	NPC* npc;
};

