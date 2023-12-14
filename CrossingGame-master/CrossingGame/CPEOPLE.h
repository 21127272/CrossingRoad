#pragma once

#include "CANIMAL.h"
#include "CVEHICLE.h"
#include "CLIGHT.h"
#include "GameSound.h"
#include "CPOINT.h"


class CPEOPLE {
private:
	CPOINT pos;
	int level = 0;
	int score = 0;
	int height = 3;
	int width = 3;
	int forward = 0;
	int back = 0;
	Sound sound;
public:
	// Constructor
	CPEOPLE() {
		pos.setXY(36, 26);
	}

	// Getter functions
	int getX();
	int getY();
	int getPlayerScore();
	int getForwardMovement();
	int getBackwardMovement();
	int getCharacterHeight();
	int getCharacterWidth();

	// Update functions
	void updatePlayerScore();
	void updatePosition(int, int);

	// Drawing and movement functions
	void drawCharacter(int, int); 
	void deleteCharacter(int, int); 
	void goUp(int&);            
	void goLeft(int&);          
	void goRight(int&);         
	void goDown(int&);         

	// Collision and completion checks
	bool checkCollision(CVEHICLE*);
	bool checkFinishLine();
};