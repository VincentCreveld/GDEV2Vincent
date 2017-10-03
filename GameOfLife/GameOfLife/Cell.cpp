#include "Cell.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#include <iostream>



Cell::Cell(int xPos, int yPos, int seed)
{
	this->xPos = xPos;
	this->yPos = yPos;
	srand(xPos + yPos + seed * 2);
	std::cout << rand() % 2 << std::endl;
	if (rand() % 2 == 1) {
		currentState = true;
	}
	else
		currentState = false;
	prevState = currentState;
}
bool Cell::GetState() {
	return prevState;
}

void Cell::SaveState() {
	prevState = currentState;
}

void Cell::SetState(bool c) {
	currentState = c;
}

std::string Cell::Display() {
	if (currentState == false) {
		return "X";
	}
	else {
		return "0";
	}
}

int Cell::getYPos()
{
	return yPos;
}

int Cell::getXPos()
{
	return xPos;
}


