#ifndef CTRUCK_H_INCLUDED
#define CTRUCK_H_INCLUDED

#include "CVEHICLE.h"

#define TRUCK_HEIGHT 3
#define TRUCK_WIDTH 9

class CTRUCK : public CVEHICLE
{
	char** shape;
public:
	CTRUCK(CPOINT);
	CTRUCK();
	~CTRUCK();
	char** returnShape();
	int getCharacterWidth();
	int getCharacterHeight();
	int inGameWidth();
};

#endif