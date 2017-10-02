#include "Grid.h"
#include <string>
#include <iostream>


Grid::Grid(int minNeighbours, int maxNeighbours, int birthNeighbours)
{
	this->birthNeighbours = birthNeighbours;
	this->minNeighbours = minNeighbours;
	this->maxNeighbours = maxNeighbours;
	
}
Cell * Grid::cellPositions[10][10];

void Grid::PrintGrid()
{
	//std::string bufferString;
	
	std::cout << "---------------" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		
		//bufferString = "";
		for (int j = 0; j < 10; j++)
		{
			std::cout << cellPositions[i][j]->isAlive() << std::endl;
			if (cellPositions[i][j]->isAlive() == 1) {
				std::cout << "X";
			}
			else {
				std::cout << " ";
			}

		}
		std::cout << std::endl;
	}
	std::cout << "---------------" << std::endl;
}

void Grid::AddCell(Cell* c,int i,int j)
{
	std::cout << "Adding cell" << std::endl;
	cellPositions[i][j] = c;
}

void Grid::UpdatePositions()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			//std::cout << "reached inside for 1 loop" << std::endl;

			cellPositions[i][j]->CheckNeighbors(i, j);
			//std::cout << "reached inside for na loop" << std::endl;

		}
	}
	std::cout << "reached inside for exit loop" << std::endl;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cellPositions[i][j]->UpdateGrid();
		}
	}
	PrintGrid();
}
