#include "Grid.h"
#include"Cell.h"
#include<iostream>

static const int MIN_NEIGHBOURGHS, MAX_NEIGHBOURS, BIRTH_NEIGHBOURS, FRAME_RATE, GRID_SIZE, SEED;

Grid::Grid()
{
	AddCells();
	amtAliveNeighbours = 0;
	generationNumber = 0;
}

void Grid::GenerateNewGen()
{
	std::cout << "--------------------" << "Generation: "<< generationNumber <<"--------------" << std::endl;
	for (int i = 0; i < Grid::GRID_SIZE; i++)
	{
		std::cout << "|";
		for (int j = 0; j < Grid::GRID_SIZE; j++)
		{
			std::cout << grid[i][j]->Display();
		}
		std::cout << "|" << std::endl;
	}
	std::cout << "------------------------------------------------------" << std::endl;

	for (int i = 0; i < Grid::GRID_SIZE; i++)
	{
		for (int j = 0; j < Grid::GRID_SIZE; j++)
		{
			grid[i][j]->SaveState();
		}
	}

	for (int i = 0; i < Grid::GRID_SIZE; i++)
	{
		for (int j = 0; j < Grid::GRID_SIZE; j++)
		{
			CheckCellNeighbours(grid[i][j]);
		}
	}

	generationNumber += 1;
}

void Grid::CheckCellNeighbours(Cell* c)
{
	int x = c->getXPos();
	int y = c->getYPos();
	int gridSize = Grid::GRID_SIZE-1;
	/*
	for (int i = x - 1; i < x + 1; i++)
	{
		for (int j = y - 1; j < y + 1; j++)
		{
			if (i >= 0 && i < 10 && j >= 0 && j < 10) {
				if (grid[i][j]->GetState() == true && (i != x && y != j)) {
					std::cout << "Reached code i: "<< i << " j: " << j << std::endl;
					amtAliveNeighbours++;
				}
			}
		}
	}*/

	// left top
	if (x > 0 && y > 0) {
		if (grid[x - 1][y - 1]->GetState()) {
			amtAliveNeighbours++;
		}
	}
	// left
	if (x > 0) {
		if (grid[x - 1][y]->GetState()) {
			amtAliveNeighbours++;
		}
	}
	// left bottom
	if (x > 0 && y < gridSize) {
		if (grid[x - 1][y + 1]->GetState()) {
			amtAliveNeighbours++;
		}
	}
	// mid top
	if (y > 0) {
		if (grid[x][y - 1]->GetState()) {
			amtAliveNeighbours++;
		}
	}
	// mid bottom
	if (y < gridSize) {
		if (grid[x][y + 1]->GetState()) {
			amtAliveNeighbours++;
		}
	}
	// right top
	if (x < gridSize && y > 0) {
		if (grid[x + 1][y - 1]->GetState()) {
			amtAliveNeighbours++;
		}
	}
	// right
	if (x < gridSize) {
		if (grid[x + 1][y]->GetState()) {
			amtAliveNeighbours++;
		}
	}
	// right bottom
	if (x < gridSize && y < gridSize) {
		if (grid[x + 1][y + 1]->GetState()) {
			amtAliveNeighbours++;
		}
	}

	//std::cout << "x: " << x << " y: " << y << std::endl;
	//std::cout << "then this code" << std::endl;
	//sstd::cout << amtAliveNeighbours << std::endl;

	
	if (c->GetState() == true && amtAliveNeighbours > MAX_NEIGHBOURS || amtAliveNeighbours < MIN_NEIGHBOURGHS) {
		//std::cout << "setting to dead" << std::endl;
		c->SetState(false);
		amtAliveNeighbours = 0;
	}
	else if (c->GetState() == false && amtAliveNeighbours == BIRTH_NEIGHBOURS) {
		//std::cout << "setting to alive" << std::endl;
		c->SetState(true);
		amtAliveNeighbours = 0;
	}
	else {
		amtAliveNeighbours = 0;
	}
}

void Grid::AddCells()
{
	for (int i = 0; i < Grid::GRID_SIZE; i++)
	{
		for (int j = 0; j < Grid::GRID_SIZE; j++)
		{
			grid[i][j] = new Cell(i, j, rand() + Grid::SEED);
		}
	}
}
