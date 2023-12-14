	#pragma once

#ifndef CVEHICLE_H_INCLUDED
#define CVEHICLE_H_INCLUDED


#include "CPOINT.h"
#include <Windows.h>
#include <iostream>
#include <mmsystem.h>


class CVEHICLE {
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


	CVEHICLE();
	CVEHICLE(CPOINT);
	virtual ~CVEHICLE() = default;
	virtual char** returnShape() = 0;

	void newPosition(int dx, int dy);

	virtual int getCharacterWidth() = 0;
	virtual int getCharacterHeight() = 0;

	virtual int inGameWidth() = 0;
	void updatePosition(int dx, int dy);
};

#endif