#pragma once
#ifndef CANIMAL_h
#define CANIMAL_h

#include "CPOINT.h"
#include "CustomControl.h"


class CANIMAL {
private:
	CPOINT pos;
public:
	CPOINT getPos();
	int getX() {
		return pos.getX();
	}
	int getY() {
		return pos.getY();
	}
	CANIMAL();
	CANIMAL(CPOINT);
	virtual ~CANIMAL() = default;
	virtual char** returnShape() = 0;
	void newPosition(int _x, int _y);
	virtual int getCharacterWidth() = 0;
	virtual int getCharacterHeight() = 0;
	void updatePosition(int _x, int _y);
};

#endif // !CANIMAL_h