#ifndef UI_H_INCLUDED
#define UI_H_INCLUDED

#include "CustomControl.h"
#include "GameSound.h"

class UI {
public:
	// Loads the background for the UI
	static void loadBackground();

	// Draws the menu box on the interface
	static void displayMenu();
	static void displayRectangle(int, int, int, int);
	static void displayInstructions();
	static void displayInfo();
	static void displayMap();
	static void displayInterface();
	static void displayGBScr();
	static void displayLevel(int);
};

#endif 
