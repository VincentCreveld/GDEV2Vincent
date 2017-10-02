#pragma once
#include "Cell.h"
class Grid
{
private:
	int minNeighbours, maxNeighbours, birthNeighbours;
public:
	Grid(int minNeightbours, int maxNeighbours,int birthNeighbours);
	void PrintGrid();
	void AddCell(Cell*, int,int);
	void UpdatePositions();
	static Cell* cellPositions[10][10];
};



