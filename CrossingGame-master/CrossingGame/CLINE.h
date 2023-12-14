#ifndef CLINE_H_INCLUDED
#define CLINE_H_INCLUDED

#include <iostream>
#include <vector>

#include "CCAR.h"
#include "CTRUCK.h"
#include "CVEHICLE.h"
#include "CPOINT.h"
#include "CustomControl.h"
#include "CBIRD.h"
#include "CDINAUSOR.h"
#include "CPEOPLE.h"

#define LINE_1 8
#define LINE_2 12
#define LINE_3 16

using namespace std;

class CLINE {
	vector<CVEHICLE*> lineData;
	bool direction; //0: to the left, 1: to the right
	bool greenLight = true;
	int speed;
	int currentRow;
	int objectInLine;
	int space;
public:
	CLINE() = default;
	CLINE(int, bool, string, int, int); //current line - direction - type of Obj - spacing - number of obj in 1 line
	~CLINE() = default;
	void setSpeed(int _x);
	void printObject(CPOINT pos, char** shape, int height, int width);
	void deleteObject(CPOINT pos, char** shape, int height, int width);
	void nextMove(CPEOPLE, bool&);
	void changeLight(bool light);
	bool getLight();
	vector<CVEHICLE*> getData();
	void setDirection(bool _x) {
		this->direction = _x;
	}
	bool getDirection() {
		return this->direction;
	}
	int getSpace() { return this->space; }
	void check(CVEHICLE*&);
};

#endif