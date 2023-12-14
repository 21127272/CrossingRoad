#include "CPOINT.h"

void CPOINT::setX(int x) {
	this->x = x;
}

void CPOINT::setY(int y) {
	this->y = y;
}

void CPOINT::setXY(int dx, int dy) {
	this->x = dx;
	this->y = dy;
}

int CPOINT::getX() {
	return x;
}

int CPOINT::getY() {
	return y;
}

CPOINT::CPOINT() {
	this->x = 0;
	this->y = 0;
}

CPOINT::CPOINT(int x, int y) {
	this->x = x;
	this->y = y;
}