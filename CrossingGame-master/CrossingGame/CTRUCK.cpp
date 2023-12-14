#include "CTRUCK.h"


CTRUCK::CTRUCK(CPOINT pos) : CVEHICLE(pos) {
	shape = new char* [TRUCK_HEIGHT];
	for (int i = 0; i < 3; i++)
	{
		shape[i] = new char[TRUCK_WIDTH];
	}
	for (int i = 0; i < TRUCK_WIDTH; i++) {
		if (i == 0) {
			shape[0][i] = ' ';
		}
		else if (i == 1 || i == 2) {
			shape[0][i] = '_';
		}
		else if (i == 3 || i == 8) {
			shape[0][i] = '.';
		}
		else {
			shape[0][i] = '-';
		}
	}
	for (int i = 0; i < TRUCK_WIDTH; i++) {

		if (i == 0 || i == 3 || i == 8)
			shape[1][i] = '|';
		else
			shape[1][i] = '_';

	}
	for (int i = 0; i < TRUCK_WIDTH; i++) {
		if (i == 0 || i == 8)
			shape[2][i] = '\'';
		else if (i == 2 || i == 6)
			shape[2][i] = '0';
		else
			shape[2][i] = '-';
	}
}

CTRUCK::CTRUCK() {
	shape = new char* [TRUCK_HEIGHT];
	for (int i = 0; i < 3; i++)
	{
		shape[i] = new char[TRUCK_WIDTH];
	}
	for (int i = 0; i < TRUCK_WIDTH; i++) {
		if (i == 0) {
			shape[0][i] = ' ';
		}
		else if (i == 1 || i == 2) {
			shape[0][i] = '_';
		}
		else if (i == 3 || i == 8) {
			shape[0][i] = '.';
		}
		else {
			shape[0][i] = '-';
		}
	}
	for (int i = 0; i < TRUCK_WIDTH; i++) {

		if (i == 0 || i == 3 || i == 8)
			shape[1][i] = '|';
		else
			shape[1][i] = '_';

	}
	for (int i = 0; i < TRUCK_WIDTH; i++) {
		if (i == 0 || i == 8)
			shape[2][i] = '\'';
		else if (i == 2 || i == 6)
			shape[2][i] = '0';
		else
			shape[2][i] = '-';
	}
}

CTRUCK::~CTRUCK() {
	for (int i = 0; i < TRUCK_HEIGHT; i++)
		delete[] shape[i];
	delete[] shape;
	delete[] shape;
}

char** CTRUCK::returnShape() {
	return shape;
}

int CTRUCK::getCharacterWidth() {
	return TRUCK_WIDTH;
}

int CTRUCK::getCharacterHeight() {
	return TRUCK_HEIGHT;
}

int CTRUCK::inGameWidth() {
	return 6;
}