#include "Cell.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#include <iostream>
#include "Grid.h"



Cell::Cell(int minNeighbours, int maxNeighbours, int birthNeighbours)
{
	this->birthNeighbours = birthNeighbours;
	this->minNeighbours = minNeighbours;
	this->maxNeighbours = maxNeighbours;
	srand(time(NULL));
	if (rand() % 2 == 1) {
		Die();
	}
	else
		Birth();
	UpdateGrid();
}

void Cell::CheckNeighbors(int x, int y)
{
	int amtAliveNeighbors = 0;
	for (int i = x-1; i < x + 1; i++)
	{
		for (int j = y - 1; j < y + 1; j++)
		{
			//std::cout << "reached inside cell loop"  << i << j << std::endl;

			if (i >= 0 && i < 10 && j >= 0 && j < 10) {
				if (Grid::cellPositions[i][j]->isAlive()) {
					amtAliveNeighbors += 1;
				}
			}
		}
	}
	if (cellState == alive && amtAliveNeighbors > maxNeighbours || amtAliveNeighbors < minNeighbours)
		Die();
	else if (cellState == dead && amtAliveNeighbors == birthNeighbours)
		Birth();
}

void Cell::Birth() {
	//std::cout << "Cell alive" << std::endl;
	nextState = alive;
}

void Cell::Die() {
	//std::cout << "Cell dead" << std::endl;
	nextState = dead;
}

void Cell::UpdateGrid() {
	cellState = nextState;
}

bool Cell::isAlive() {
	//std::cout << "cellstate" << cellState << std::endl;
	//if (cellState = alive) return true; else if (cellState = dead) return false;

	if (cellState = alive) {
		return true;
	}
	else if (cellState = dead) {
		return false;
	}
	//return true;
}