#pragma once

#ifndef CBIRD_h
#define CBIRD_h

#include "CVEHICLE.h"
#define BIRD_HEIGHT 3
#define BIRD_WIDTH 5

class CBIRD : public CVEHICLE {
private:
	char** shape;

public:
	CBIRD(CPOINT);
	CBIRD();
	~CBIRD();
	char** returnShape();
	int getCharacterHeight();
	int getCharacterWidth();
	int inGameWidth();
};

#endif 