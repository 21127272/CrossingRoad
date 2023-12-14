#include "CVEHICLE.h";

CVEHICLE::CVEHICLE() {}

CVEHICLE::CVEHICLE(CPOINT point) :pos(point) {}

CPOINT CVEHICLE::getPos() {
	return this->pos;
}

void CVEHICLE::newPosition(int dx, int dy) {
	this->pos.setX(dx);
	this->pos.setY(dy);
}

int CVEHICLE::getCharacterHeight() {
	return 3;
}

void CVEHICLE::updatePosition(int dx, int dy) {
	pos.setXY(pos.getX() + dx, pos.getY() + dy);
}