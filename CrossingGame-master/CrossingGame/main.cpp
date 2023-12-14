#include "Header.h"
#include "CustomControl.h"
#include "MENU.h"
#include "GameSound.h"

// global mutex
mutex mtx;

int main() {
	CustomControl::InitializeConsole();
	Sound s;
	s.playBackgroundSound(true);

	MENU game;
	game.ShowMainMenu();
}