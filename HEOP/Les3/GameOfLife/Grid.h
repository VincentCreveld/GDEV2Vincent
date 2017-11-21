#pragma once
#include "Cell.h"
/*
	Interessante seeds:
	3246
	46532

*/


class Grid
{
	
public:
	static const int MIN_NEIGHBOURGHS = 2, MAX_NEIGHBOURS = 3, BIRTH_NEIGHBOURS = 3, FRAME_RATE = 16, GRID_SIZE = 20, SEED = 1;
	Grid();
	void GenerateNewGen();
	void CheckCellNeighbours(Cell* c);
	void AddCells();
	Cell* grid[Grid::GRID_SIZE][Grid::GRID_SIZE];
private:
	int amtAliveNeighbours;
	int generationNumber;

};

