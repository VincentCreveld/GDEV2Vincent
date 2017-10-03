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
	bool currentState;
	bool prevState;
	int getXPos();
	int getYPos();
private:
	int xPos, yPos;
	
};

