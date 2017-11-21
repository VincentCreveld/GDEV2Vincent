#include <iostream>
#include <time.h>
#include "Grid.h"

Grid* grid;

int main() {
	clock_t t;
	float deltaTime = 0;
	float timePassed = 0;
	t = clock();
	double framerate = (double)1/Grid::FRAME_RATE;

	grid = new Grid();


	///*
	while (true) {
		deltaTime = ((float)(clock() - t)) / CLOCKS_PER_SEC;
		t = clock();
		timePassed += deltaTime;

		if (timePassed > (framerate)) {
			grid->GenerateNewGen();
			std::cout << std::flush;
			timePassed -= (framerate);
		}

	}
	//*/
	//grid->GenerateNewGen();
	system("pause");
	return 0;
}