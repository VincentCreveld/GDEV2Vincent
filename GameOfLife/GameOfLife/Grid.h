#pragma once
#include "Cell.h"
/*
	Interessante seeds:
	3246


*/


class Grid
{
	
public:
	static const int MIN_NEIGHBOURGHS = 2, MAX_NEIGHBOURS = 3, BIRTH_NEIGHBOURS = 3, FRAME_RATE = 8, GRID_SIZE = 50, SEED = 98642;
	Grid();
	void GenerateNewGen();
	void CheckCellNeighbours(Cell* c);
	void AddCells();
	Cell* grid[Grid::GRID_SIZE][Grid::GRID_SIZE];
private:
	int amtAliveNeighbours;
	int generationNumber;

};

