#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "Header.h"
#include "UI.h"
#include "CustomControl.h"
#include "GameSound.h"
#include "CGAME.h"

class MENU {
public:	
    void ShowMainMenu();
    void DisplayRulesMenu();
    void DisplaySettingsMenu();
    void startGame();
    void loadExistingGame();
};

#endif