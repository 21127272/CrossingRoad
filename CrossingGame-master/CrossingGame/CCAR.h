#ifndef CCAR_H_INCLUDED
#define CCAR_H_INCLUDED

#include "CVEHICLE.h"

#define CAR_HEIGHT 3
#define CAR_WIDTH 9

class CCAR : public CVEHICLE {
	char** shape;
public:
	CCAR(CPOINT);
	CCAR();
	~CCAR();
	char** returnShape();
	int getCharacterWidth();
	int getCharacterHeight();
	int inGameWidth();
};

#endif // !cCar_h
