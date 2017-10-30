#pragma once
#include <string>
class Cell
{
	
public:
	Cell(int xPos, int yPos, int seed = 0);
	bool GetState();
	void SaveState();
	void SetState(bool c);
	std::string Display();

	int getXPos();
	int getYPos();
private:
	int xPos, yPos;
	bool currentState;
	bool prevState;
};

