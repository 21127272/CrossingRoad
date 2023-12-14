#ifndef CDINAUSOR_H_INCLUDED
#define CDINAUSOR_H_INCLUDED

#include "CVEHICLE.h"
#define DINO_HEIGHT 3
#define DINO_WIDTH 6

class CDINAUSOR : public CVEHICLE {
private:
	char** shape;

public:
	CDINAUSOR(CPOINT);
	CDINAUSOR();
	~CDINAUSOR();
	char** returnShape();
	int getCharacterHeight();
	int getCharacterWidth();
	int inGameWidth();
};

#endif 