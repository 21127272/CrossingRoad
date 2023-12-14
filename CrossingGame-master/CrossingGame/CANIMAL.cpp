#include "CANIMAL.h"

CANIMAL::CANIMAL() {}

CANIMAL::CANIMAL(CPOINT point) : pos(point) {}

CPOINT CANIMAL::getPos() {
	return this->pos;
}

void CANIMAL::newPosition(int _x, int _y) {
	this->pos.setX(_x);
	this->pos.setY(_y);
}

int CANIMAL::getCharacterHeight() {
	return 3;
}

void CANIMAL::updatePosition(int _x, int _y) {
	if ((pos.getY() + _y) >= 31 ) {
		pos.setXY(4, 3);
	}
	else
		pos.setXY(pos.getX() + _x, pos.getY() + _y);
}