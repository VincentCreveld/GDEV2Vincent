#pragma once
#include "Cell.h"

class Grid
{
	const int MIN_NEIGHBOURGHS = 2, MAX_NEIGHBOURS = 3, BIRTH_NEIGHBOURS = 3;
public:
	Grid();
	void GenerateNewGen();
	void CheckCellNeighbours(Cell* c);
	void AddCells();
	Cell* grid[10][10];
private:
	int amtAliveNeighbours;

};

