#include <iostream>
#include <time.h>
#include "Grid.h"

const int MIN_NEIGHBOURS = 2, MAX_NEIGHBOURS = 3, BIRTH_NEIGHBOURS = 3;


Grid* grid;

int main() {
	clock_t t;
	float deltaTime = 0;
	float timePassed = 0;
	t = clock();
	double framerate = 0.0166667;

	grid = new Grid(MIN_NEIGHBOURS, MAX_NEIGHBOURS, BIRTH_NEIGHBOURS);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			grid->AddCell(new Cell(MIN_NEIGHBOURS, MAX_NEIGHBOURS, BIRTH_NEIGHBOURS), i, j);
			std::cout << i << " " << j << std::endl;
		}
	}
	std::cout << "reached code1" << std::endl;
	while (true) {
		std::cout << "reached inside while loop" << std::endl;
		deltaTime = ((float)(clock() - t)) / CLOCKS_PER_SEC;
		t = clock();
		timePassed += deltaTime;

		if (timePassed > (framerate)) {
			std::cout << "reached inside execute block" << std::endl;
			grid->UpdatePositions();
			//grid->PrintGrid();
			system("CLS");
			timePassed -= (framerate);
		}

	}
	std::cout << "reached code2" << std::endl;
	//grid->PrintGrid();
	//system("pause");
	return 0;
}