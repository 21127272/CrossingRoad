#include "CustomControl.h";

HWND consoleWindow = GetConsoleWindow();
HANDLE consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

void CustomControl::InitializeConsole() {
	ConfigureFont();
	CenterConsoleWindow();
	AdjustConsoleWindow();
	UpdateConsoleTitle();
	HideVerticalScrollBar();
	ToggleCursorVisibility(false);
	DeactivateMouse();
	system("color F0");
}
void CustomControl::AdjustConsoleWindow() {
	LONG windowStyle = GetWindowLong(consoleWindow, GWL_STYLE);

	// Remove the maximize box and thick frame
	windowStyle = windowStyle & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);

	// Set the modified style back to the console window
	SetWindowLong(consoleWindow, GWL_STYLE, windowStyle);
}
void CustomControl::CenterConsoleWindow() {
	RECT clientRect, windowRect;
	GetClientRect(consoleWindow, &clientRect);
	GetWindowRect(consoleWindow, &windowRect);

	int posX = (GetSystemMetrics(SM_CXSCREEN) - WIDTH_CONSOLE) / 2;
	int posY = (GetSystemMetrics(SM_CYSCREEN) - HEIGH_CONSOLE) / 2;

	MoveWindow(consoleWindow, posX, posY, WIDTH_CONSOLE, HEIGH_CONSOLE, TRUE);
}
void CustomControl::gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(consoleOutput, coord);
}
void CustomControl::HideVerticalScrollBar() {
	ShowScrollBar(consoleWindow, SB_BOTH, 0);
}
void CustomControl::ConfigureFont() {
	CONSOLE_FONT_INFOEX fontInfo;
	fontInfo.cbSize = sizeof(fontInfo);
	GetCurrentConsoleFontEx(consoleOutput, FALSE, &fontInfo);

	// Modify font size and type
	fontInfo.dwFontSize.X = 12;
	fontInfo.dwFontSize.Y = 24;
	wcscpy_s(fontInfo.FaceName, L"Consolas");

	// Set the updated font information
	SetCurrentConsoleFontEx(consoleOutput, FALSE, &fontInfo);

}
void CustomControl::DeactivateMouse() {
	DWORD previousMode;
	HANDLE inputHandle = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleMode(inputHandle, &previousMode);
	SetConsoleMode(inputHandle, previousMode & ~ENABLE_QUICK_EDIT_MODE);
}
void CustomControl::ToggleCursorVisibility(bool show) {
	CONSOLE_CURSOR_INFO cursorInfo = { 1, show };
	SetConsoleCursorInfo(consoleOutput, &cursorInfo);
}
void CustomControl::UpdateConsoleTitle() {
	SetConsoleTitleA("Crossing CGAME");
}

void CustomControl::SetConsoleTextColor(int background, int text) {
	SetConsoleTextAttribute(consoleOutput, background * 16 + text);
}
int CustomControl::GetUserInputFromConsole() {
	int userInput = _getch();

	// Check for extended keys (arrow keys)
	if (userInput == 0 || userInput == 224) {
		switch (_getch()) {
		case UP:
			return 2;
		case LEFT:
			return 3;
		case RIGHT:
			return 4;
		case DOWN:
			return 5;
		default:
			return 0;
		}
	}
	else {
		// Check for specific keys
		switch (userInput) {
		case ESC:
			return 1;
		case 'W':
		case 'w':
			return 2;
		case 'A':
		case 'a':
			return 3;
		case 'D':
		case 'd':
			return 4;
		case 'S':
		case 's':
			return 5;
		case ENTER:
			return 6;
		case 'P':
		case 'p':
			return 7;
		case 'L':
		case 'l':
			return 8;
		case 'H':
		case 'h':
			return 9;
		default:
			return 0;
		}
	}

}