#pragma once
#include "Specialization.h"
class Shaman : public Specialization
{
public:
	Shaman(NPC* npc);
	void Render() override;
private:
	NPC* npc;
};

