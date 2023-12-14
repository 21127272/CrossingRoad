#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

#include "Header.h"

class CustomControl {
public:
	static void InitializeConsole();
	static void AdjustConsoleWindow();//
    static void CenterConsoleWindow();
    static void SetConsoleTextColor(int, int);
    static void gotoxy(int, int);//
    static void HideVerticalScrollBar();
    static void ConfigureFont();
    static void DeactivateMouse();//
    static void ToggleCursorVisibility(bool);
    static void UpdateConsoleTitle();
    static int GetUserInputFromConsole();
};

#endif