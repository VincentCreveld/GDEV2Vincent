#include <iostream>
#include <time.h>
#include "Grid.h"

Grid* grid;

int main() {
	clock_t t;
	float deltaTime = 0;
	float timePassed = 0;
	t = clock();
	double framerate = 0.0166667;

	grid = new Grid();


	/*
	while (true) {
		deltaTime = ((float)(clock() - t)) / CLOCKS_PER_SEC;
		t = clock();
		timePassed += deltaTime;

		if (timePassed > (framerate)) {
			grid->GenerateNewGen();
			system("CLS");
			timePassed -= (framerate);
		}

	}*/
	grid->GenerateNewGen();
	system("pause");
	return 0;
}