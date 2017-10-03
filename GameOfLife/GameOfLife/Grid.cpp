#include "Grid.h"
#include"Cell.h"
#include<iostream>

Grid::Grid()
{
	AddCells();
	amtAliveNeighbours = 0;
}

void Grid::GenerateNewGen()
{
	std::cout << "-------------" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			std::cout << grid[i][j]->Display();
		}
		std::cout << std::endl;
	}
	std::cout << "-------------" << std::endl;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			grid[i][j]->SaveState();
		}
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			CheckCellNeighbours(grid[i][j]);
		}
	}

	
}

void Grid::CheckCellNeighbours(Cell* c)
{
	int x = c->getXPos();
	int y = c->getYPos();
	int gridSize = 10;
	/*
	for (int i = c->getXPos() - 1; i < c->getXPos() + 1; i++)
	{
		for (int j = c->getYPos() - 1; j < c->getYPos() + 1; j++)
		{
			if (i >= 0 && i < 10 && j >= 0 && j < 10) {
				if (grid[i][j]->GetState() == true && (i != c->getXPos() && c->getYPos() != j)) {
					std::cout << "Reached code i: "<< i << " j: " << j << std::endl;
					amtAliveNeighbours++;
				}
			}
		}
	}*/

	// left top
	if (x > 0 && y > 0) {
		if (grid[x - 1][y - 1]->prevState) {
			amtAliveNeighbours++;
		}
	}
	// left
	if (x > 0) {
		if (grid[x - 1][y]->prevState) {
			amtAliveNeighbours++;
		}
	}
	// left bottom
	if (x > 0 && y < gridSize) {
		if (grid[x - 1][y + 1]->prevState) {
			amtAliveNeighbours++;
		}
	}
	// mid top
	if (y > 0) {
		if (grid[x][y - 1]->prevState) {
			amtAliveNeighbours++;
		}
	}
	// mid bottom
	if (y < gridSize) {
		if (grid[x][y + 1]->prevState) {
			amtAliveNeighbours++;
		}
	}
	// right top
	if (x < gridSize && y > 0) {
		if (grid[x + 1][y - 1]->prevState) {
			amtAliveNeighbours++;
		}
	}
	// right
	if (x < gridSize) {
		if (grid[x + 1][y]->prevState) {
			amtAliveNeighbours++;
		}
	}
	// right bottom
	if (x < gridSize && y < gridSize) {
		if (grid[x + 1][y + 1]->prevState) {
			amtAliveNeighbours++;
		}
	}

	std::cout << "then this code" << std::endl;
	std::cout << amtAliveNeighbours << std::endl;

	
	if (c->GetState() == true && amtAliveNeighbours > MAX_NEIGHBOURS || amtAliveNeighbours < MIN_NEIGHBOURGHS) {
		std::cout << "setting to dead" << std::endl;
		c->SetState(false);
		amtAliveNeighbours = 0;
	}
	else if (c->GetState() == false && amtAliveNeighbours == BIRTH_NEIGHBOURS) {
		std::cout << "setting to alive" << std::endl;
		c->SetState(true);
		amtAliveNeighbours = 0;
	}
	else {
		amtAliveNeighbours = 0;
	}
}

void Grid::AddCells()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			grid[i][j] = new Cell(i, j, rand());
		}
	}
}
