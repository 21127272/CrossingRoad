#include "UI.h"

void UI::displayInterface() {
	system("cls");
	displayMap();
	displayInstructions();
	displayInfo();
}
void UI::displayMenu() {
	/*CustomControl::SetConsoleTextColor(BRIGHT_WHITE, GREEN);
	for (int i = 40; i < 83; i++) {
		CustomControl::gotoxy(i, 11);
		putchar(178);
		CustomControl::gotoxy(i, 23);
		putchar(178);
	}

	for (int i = 11; i < 24; i++) {
		CustomControl::gotoxy(40, i);
		putchar(219);
		CustomControl::gotoxy(82, i);
		putchar(219);
	}*/
}
void UI::displayRectangle(int left, int top, int width, int height) {
	CustomControl::gotoxy(left, top);
	putchar(218);
	for (int i = 0; i < width; i++)
		putchar(196);
	putchar(191);

	int i = 0;
	for (; i < height; i++) {
		CustomControl::gotoxy(left, top + i + 1);
		putchar(179);
		CustomControl::gotoxy(left + width + 1, top + i + 1);
		putchar(179);
	}

	CustomControl::gotoxy(left, top + i);
	putchar(192);
	for (i = 0; i < width; i++)
		putchar(196);
	putchar(217);
}
void UI::loadBackground() {
	CustomControl::gotoxy(5, 2); CustomControl::SetConsoleTextColor(BRIGHT_WHITE, LIGHT_PURPLE); cout << "  _______  ______    _______  _______  _______  ___   __    _  _______    _______  _______  __   __  _______ \n";
	CustomControl::gotoxy(5, 3); CustomControl::SetConsoleTextColor(BRIGHT_WHITE, LIGHT_PURPLE); cout << " |       ||    _ |  |       ||       ||       ||   | |  |  | ||       |  |       ||   _   ||  |_|  ||       |\n";
	CustomControl::gotoxy(5, 4); CustomControl::SetConsoleTextColor(BRIGHT_WHITE, LIGHT_PURPLE); cout << " |       ||   | ||  |   _   ||  _____||  _____||   | |   |_| ||    ___|  |    ___||  |_|  ||       ||    ___|\n";
	CustomControl::gotoxy(5, 5); CustomControl::SetConsoleTextColor(BRIGHT_WHITE, LIGHT_BLUE); cout << " |       ||   |_||_ |  | |  || |_____ | |_____ |   | |       ||   | __   |   | __ |       ||       ||   |___ \n";
	CustomControl::gotoxy(5, 6); CustomControl::SetConsoleTextColor(BRIGHT_WHITE, LIGHT_BLUE); cout << " |      _||    __  ||  |_|  ||_____  ||_____  ||   | |  _    ||   ||  |  |   ||  ||       ||       ||    ___|\n";
	CustomControl::gotoxy(5, 7); CustomControl::SetConsoleTextColor(BRIGHT_WHITE, LIGHT_BLUE); cout << " |     |_ |   |  | ||       | _____| | _____| ||   | | | |   ||   |_| |  |   |_| ||   _   || ||_|| ||   |\n";
	CustomControl::gotoxy(5, 7); CustomControl::SetConsoleTextColor(BRIGHT_WHITE, LIGHT_PURPLE); cout << " |     |_ |   |  | ||       | _____| | _____| ||   | | | |   ||   |_| |  |   |_| ||   _   || ||_|| ||   |___ \n";
	CustomControl::gotoxy(5, 8); CustomControl::SetConsoleTextColor(BRIGHT_WHITE, LIGHT_PURPLE); cout << " |_______||___|  |_||_______||_______||_______||___| |_|  |__||_______|  |_______||__| |__||_|   |_||_______|";
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, LIGHT_AQUA);
	CustomControl::gotoxy(23, 5); cout << " /";
	CustomControl::gotoxy(23, 6); cout << "//";
	CustomControl::gotoxy(22, 7); cout << "//";
	CustomControl::gotoxy(21, 8); cout << "//";
	CustomControl::gotoxy(20, 9); cout << "//";
	CustomControl::gotoxy(19, 10); cout << "//";
	CustomControl::gotoxy(18, 11); cout << "//";
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, LIGHT_RED);
	CustomControl::gotoxy(21, 11); cout << "*_*";
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, LIGHT_AQUA);
	CustomControl::gotoxy(17, 12); cout << "//";
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, LIGHT_RED);
	CustomControl::gotoxy(20, 12); cout << "=====";
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, LIGHT_AQUA);

	CustomControl::gotoxy(25, 13); cout << "\\\\";
	CustomControl::gotoxy(26, 14); cout << "\\\\";
	CustomControl::gotoxy(27, 15); cout << "\\\\";
	CustomControl::gotoxy(28, 16); cout << "\\\\";
	CustomControl::gotoxy(29, 17); cout << "\\\\";
	CustomControl::gotoxy(30, 18); cout << "\\\\";
	CustomControl::gotoxy(31, 19); cout << "\\\\";
	CustomControl::gotoxy(32, 20); cout << "\\\\";
	CustomControl::gotoxy(33, 21); cout << "\\\\";
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, LIGHT_AQUA);
	CustomControl::gotoxy(37, 14); cout << "||";
	CustomControl::gotoxy(37, 15); cout << "||";
	CustomControl::gotoxy(37, 16); cout << "||";
	CustomControl::gotoxy(37, 17); cout << "||";
	CustomControl::gotoxy(37, 18); cout << "||";
	CustomControl::gotoxy(37, 19); cout << "||";
	CustomControl::gotoxy(37, 20); cout << "||";
	CustomControl::gotoxy(37, 21); cout << "||";

	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, LIGHT_AQUA);
	CustomControl::gotoxy(16, 13); cout << "//";
	CustomControl::gotoxy(16, 14); cout << "\\\\";
	CustomControl::gotoxy(17, 15); cout << "\\\\";
	CustomControl::gotoxy(18, 16); cout << "\\\\";
	CustomControl::gotoxy(19, 17); cout << "\\\\";
	CustomControl::gotoxy(20, 18); cout << "\\\\";
	CustomControl::gotoxy(21, 19); cout << "\\\\";
	CustomControl::gotoxy(22, 20); cout << "\\\\";
	CustomControl::gotoxy(23, 21); cout << "\\\\";
	CustomControl::gotoxy(24, 22); cout << "\\\\";
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, LIGHT_RED);

	CustomControl::gotoxy(34, 22); cout << "=====";
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, LIGHT_AQUA);
	CustomControl::gotoxy(25, 23); cout << "\\\\";
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, LIGHT_RED);
	CustomControl::gotoxy(35, 23); cout << "*_*";
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, LIGHT_AQUA);

	CustomControl::gotoxy(26, 24); cout << "\\\\";
	CustomControl::gotoxy(27, 25); cout << "\\\\";
	CustomControl::gotoxy(28, 26); cout << "\\\\";
	CustomControl::gotoxy(29, 27); cout << "\\\\";
	CustomControl::gotoxy(30, 28); cout << "\\\\";

	CustomControl::gotoxy(103, 4); cout << "\\";
	CustomControl::gotoxy(103, 5); cout << "\\\\";
	CustomControl::gotoxy(104, 6); cout << "\\\\";
	CustomControl::gotoxy(105, 7); cout << "\\\\";
	CustomControl::gotoxy(106, 8); cout << "\\\\";
	CustomControl::gotoxy(107, 9); cout << "\\\\";
	CustomControl::gotoxy(108, 10); cout << "\\\\";
	CustomControl::gotoxy(109, 11); cout << "\\\\";

	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, LIGHT_RED);
	CustomControl::gotoxy(105, 11); cout << "*_*";
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, LIGHT_AQUA);
	CustomControl::gotoxy(110, 12); cout << "\\\\";
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, LIGHT_RED);
	CustomControl::gotoxy(104, 12); cout << "=====";
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, LIGHT_AQUA);

	CustomControl::gotoxy(102, 13); cout << "//";
	CustomControl::gotoxy(101, 14); cout << "//";
	CustomControl::gotoxy(100, 15); cout << "//";
	CustomControl::gotoxy(99, 16); cout << "//";
	CustomControl::gotoxy(98, 17); cout << "//";
	CustomControl::gotoxy(97, 18); cout << "//";
	CustomControl::gotoxy(96, 19); cout << "//";
	CustomControl::gotoxy(95, 20); cout << "//";
	CustomControl::gotoxy(94, 21); cout << "//";
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, LIGHT_AQUA);
	CustomControl::gotoxy(90, 14); cout << "||";
	CustomControl::gotoxy(90, 15); cout << "||";
	CustomControl::gotoxy(90, 16); cout << "||";
	CustomControl::gotoxy(90, 17); cout << "||";
	CustomControl::gotoxy(90, 18); cout << "||";
	CustomControl::gotoxy(90, 19); cout << "||";
	CustomControl::gotoxy(90, 20); cout << "||";
	CustomControl::gotoxy(90, 21); cout << "||";
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, LIGHT_AQUA);
	CustomControl::gotoxy(111, 13); cout << "\\\\";
	CustomControl::gotoxy(111, 14); cout << "//";
	CustomControl::gotoxy(110, 15); cout << "//";
	CustomControl::gotoxy(109, 16); cout << "//";
	CustomControl::gotoxy(108, 17); cout << "//";
	CustomControl::gotoxy(107, 18); cout << "//";
	CustomControl::gotoxy(106, 19); cout << "//";
	CustomControl::gotoxy(105, 20); cout << "//";
	CustomControl::gotoxy(104, 21); cout << "//";
	CustomControl::gotoxy(103, 22); cout << "//";


	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, LIGHT_RED);
	CustomControl::gotoxy(90, 22); cout << "=====";
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, LIGHT_AQUA);

	CustomControl::gotoxy(102, 23); cout << "//";
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, LIGHT_RED);
	CustomControl::gotoxy(91, 23); cout << "*_*";
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, LIGHT_AQUA);

	CustomControl::gotoxy(101, 24); cout << "//";
	CustomControl::gotoxy(100, 25); cout << "//";
	CustomControl::gotoxy(99, 26); cout << "//";
	CustomControl::gotoxy(98, 27); cout << "//";
	CustomControl::gotoxy(97, 28); cout << "//";

	CustomControl::gotoxy(32, 28); cout << "=====================================";
	CustomControl::gotoxy(69, 28); cout << "============================";

}
void UI::displayInstructions() {
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, BLACK);
	displayRectangle(79, 14, 14, 2);
	displayRectangle(98, 14, 14, 2);
	displayRectangle(79, 17, 14, 2);
	displayRectangle(98, 17, 14, 2);

	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, PURPLE);
	CustomControl::gotoxy(83, 15);
	cout << "L : Save";
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, RED);
	CustomControl::gotoxy(102, 15);
	cout << "H : Help";
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, GREEN);
	CustomControl::gotoxy(83, 18);
	cout << "P : Pause";
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, GRAY);
	CustomControl::gotoxy(101, 18);
	cout << "Esc : Exit";
}

void UI::displayMap() {
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, BLACK);
	int left = 4, top = 5, size = 8;
	//Draw top lines
	CustomControl::gotoxy(left + 1, top);
	putchar(201);
	for (int i = 1; i < size * 8; i++) {
		Sleep(5);
		if (i % 8 == 0)
			putchar(205);
		else
			putchar(205);
	}
	putchar(187);

	//Draw right vertical lines
	for (int i = 1; i < size * 3; i++) {
		Sleep(10);
		CustomControl::gotoxy(size * 8 + left + 1, i + top);
		if (i % 4 != 0)
			putchar(186);
		else
			putchar(186);
	}
	CustomControl::gotoxy(size * 8 + left + 1, size * 3 + top);
	putchar(188);

	//Draw bot lines
	for (int i = 1; i < size * 8; i++) {
		CustomControl::gotoxy(size * 8 + left - i + 1, size * 3 + top);
		Sleep(5);
		if (i % 8 == 0)
			putchar(205);
		else
			putchar(205);
	}
	CustomControl::gotoxy(left + 1, size * 3 + top);
	putchar(200);

	//Draw left vertical lines
	for (int i = 1; i < size * 3; i++) {
		Sleep(10);
		CustomControl::gotoxy(left + 1, size * 3 + top - i);
		if (i % 4 != 0)
			putchar(186);
		else
			putchar(186);
	}

	//Draw horizontal lines
	for (int i = 1; i < size * 8; i++) {
		for (int j = 4; j < size * 3; j += 4) {
			CustomControl::gotoxy(i + left + 1, j + top);
				putchar(196);
		}
		Sleep(5);
	}

	for (int j = 1; j <= 3; j++) {
		CustomControl::gotoxy(left + 2, j + top);
		for (int i = 1; i < size * 8; i++) {
			Sleep(5);
			if (i % 2 == 0 && j % 2 == 0)
				putchar(178);
			else if(i % 2 != 0 && j % 2 != 0)
				putchar(178);
			else
				putchar(176);
		}
	}
}

void UI::displayInfo() {
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, BLACK);
	displayRectangle(79, 3, 33, 10);
	displayRectangle(80, 4, 31, 2);
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, YELLOW);
	CustomControl::gotoxy(87, 5);
	cout << "PLAYER'S INFORMATION";	
}

void UI::displayGBScr() {
	system("cls");
	Sleep(500);

	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, BLACK);
	

 CustomControl::gotoxy(30, 10); cout << "                             _   _                    " << endl;
 CustomControl::gotoxy(30, 11); cout << "                            | | | |                   " << endl;
 CustomControl::gotoxy(30, 12); cout << "  __ _    ___     ___     __| | | |__    _   _    ___ " << endl;
 CustomControl::gotoxy(30, 13); cout << " / _` |  / _ \\   / _ \\   / _` | | '_ \\  | | | |  / _ \\" << endl;
 CustomControl::gotoxy(30, 14); cout << "| (_| | | (_) | | (_) | | (_| | | |_) | | |_| | |  __/ " << endl;
 CustomControl::gotoxy(30, 15); cout << " \\__, |  \\___/   \\___/   \\__,_| |_.__/   \\__, |  \\___|" << endl;
 CustomControl::gotoxy(30, 16); cout << "   __/ |                                   __/ |       " << endl;
 CustomControl::gotoxy(30, 17); cout << "  |___/                                   |___/        " << endl;
	
	Sound s;
	s.endGameSound();
	
	Sleep(200);
	//CustomControl::SetConsoleTextColor(BRIGHT_WHITE, BRIGHT_WHITE);
	Sleep(1500);
	exit(0);
}
void UI::displayLevel(int level) {
	const char levelASCII[] = R"(  
			  _             _ 
			 | |_____ _____| |
			 | / -_) V / -_) |
			 |_\___|\_/\___|_|
)";
	
	CustomControl::gotoxy(0, 0);
	cout << levelASCII;
	if (level == 1) {
		CustomControl::gotoxy(45, 1); cout << " _";
		CustomControl::gotoxy(45, 2); cout << "/ |";
		CustomControl::gotoxy(45, 3); cout << "| |";
		CustomControl::gotoxy(45, 4); cout << "|_|";
	}
	else if (level == 2) {
		CustomControl::gotoxy(45, 1); cout << " ___ ";
		CustomControl::gotoxy(45, 2); cout << "|_  )";
		CustomControl::gotoxy(45, 3); cout << " / / ";
		CustomControl::gotoxy(45, 4); cout << "/___|";
	}
	else if (level == 3) {
		CustomControl::gotoxy(45, 1); cout << " ____";
		CustomControl::gotoxy(45, 2); cout << "|__ /";
		CustomControl::gotoxy(45, 3); cout << " |_ \\";
		CustomControl::gotoxy(45, 4); cout << "|___/ ";
	}
	else if (level == 4) {
		CustomControl::gotoxy(45, 1); cout << " _ _ ";
		CustomControl::gotoxy(45, 2); cout << "| | | ";
		CustomControl::gotoxy(45, 3); cout << "|_  _|";
		CustomControl::gotoxy(45, 4); cout << "  |_| ";
	}
	else if (level == 5) {
		CustomControl::gotoxy(45, 1); cout << " ___ ";
		CustomControl::gotoxy(45, 2); cout << "| __| ";
		CustomControl::gotoxy(45, 3); cout << "|__ \\ ";
		CustomControl::gotoxy(45, 4); cout << "|___/ ";
	}
	else
		return;
}