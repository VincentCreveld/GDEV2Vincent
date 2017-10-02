#pragma once
class Cell
{
public:
	Cell(int minNeighbours, int maxNeighbours, int birthNeighbours);
	void CheckNeighbors(int,int);
	void Birth();
	void Die();
	void UpdateGrid();
	bool isAlive();
private:
	int maxNeighbours, minNeighbours, birthNeighbours;
	enum CellState{alive, dead};
	CellState cellState;
	CellState nextState;
};

