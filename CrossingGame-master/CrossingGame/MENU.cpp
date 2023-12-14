#include "MENU.h";

void MENU::ShowMainMenu() {
	system("cls");
	UI::loadBackground();
	UI::displayMenu();
	CustomControl::gotoxy(47, 12);
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, AQUA);
	CustomControl::gotoxy(56, 13);
	cout << "  CROSSING GAME";
	int idx = 15, idx_t = 15;
	CustomControl::gotoxy(56, idx);
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, LIGHT_RED);
	cout << (char)175;
	CustomControl::gotoxy(59, 15);
	cout << "New Game   " << '\n';
	CustomControl::gotoxy(59, 16);
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, BLACK);
	cout << "Load Game       " << '\n';
	CustomControl::gotoxy(59, 17);
	cout << "Settings      " << '\n';
	CustomControl::gotoxy(59, 18);
	cout << "Help      " << '\n';
	CustomControl::gotoxy(59, 19);
	cout << "Exit      " << '\n';

	while (true) {
		char s = toupper(_getch());
		CustomControl::SetConsoleTextColor(BRIGHT_WHITE, LIGHT_AQUA);
		idx_t = idx;

		if (s == 'W' || s == UP)
			idx--;
		else if (s == 'S' || s == DOWN)
			idx++;
		if (s == ESC)
			UI::displayGBScr();

		if (idx > 19)
			idx = 15;
		else if (idx < 15)
			idx = 19;
		CustomControl::gotoxy(56, idx_t);
		cout << "  ";
		CustomControl::gotoxy(56, idx);
		CustomControl::SetConsoleTextColor(BRIGHT_WHITE, LIGHT_RED);
		cout << (char)175;
		CustomControl::gotoxy(59, 15);
		CustomControl::SetConsoleTextColor(BRIGHT_WHITE, BLACK);
		if (idx == 15)
			CustomControl::SetConsoleTextColor(BRIGHT_WHITE, LIGHT_RED);
		cout << "New Game" << '\n';
		CustomControl::gotoxy(59, 16);
		CustomControl::SetConsoleTextColor(BRIGHT_WHITE, BLACK);
		if (idx == 16)
			CustomControl::SetConsoleTextColor(BRIGHT_WHITE, LIGHT_RED);
		cout << "Load Game" << '\n';
		CustomControl::gotoxy(59, 17);
		CustomControl::SetConsoleTextColor(BRIGHT_WHITE, BLACK);
		if (idx == 17)
			CustomControl::SetConsoleTextColor(BRIGHT_WHITE, LIGHT_RED);
		cout << "Settings" << '\n';
		CustomControl::gotoxy(59, 18);
		CustomControl::SetConsoleTextColor(BRIGHT_WHITE, BLACK);
		if (idx == 18)
			CustomControl::SetConsoleTextColor(BRIGHT_WHITE, LIGHT_RED);
		cout << "Help" << '\n';
		CustomControl::gotoxy(59, 19);
		CustomControl::SetConsoleTextColor(BRIGHT_WHITE, BLACK);	
		if (idx == 19)
			CustomControl::SetConsoleTextColor(BRIGHT_WHITE, LIGHT_RED);
		cout << "Exit" << '\n';


		if (s == 13) {
			idx -= 14;
			break;
		}

	}
	switch (idx) {
	case 1:
		startGame();
		break;
	case 2:
		loadExistingGame();
		break;
	case 3:
		DisplaySettingsMenu();
		break;
	case 4:
		DisplayRulesMenu();
		break;
	case 5:
		UI::displayGBScr();
		break;
	}
}
void MENU::DisplaySettingsMenu() {
	system("cls");
	UI::loadBackground();
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, BLACK);
	UI::displayRectangle(46, 13, 35, 8);
	UI::displayRectangle(49, 18, 7, 2);
	UI::displayRectangle(72, 18, 6, 2);

	CustomControl::gotoxy(50, 15);
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, GREEN);
	Sound bgSound;
	cout << "Turn Background Music On/Off";
	string str[2] = { "On", "Off" };
	int left[] = { 47,52,59,70,74,81 }, word[] = { 32,32,175,174 }, color[] = { BLACK, GREEN }, top = 19;
	bool choice = 1;
	auto print1 = [&]() {
		int i = 0;
		while (i < 2) {
			CustomControl::SetConsoleTextColor(BRIGHT_WHITE, color[i]);
			CustomControl::gotoxy(left[choice * 3], top);        putchar(word[i * 2]);
			CustomControl::gotoxy(left[choice * 3 + 1], top);    cout << str[choice];
			CustomControl::gotoxy(left[choice * 3 + 2], top);    putchar(word[i * 2 + 1]);
			if (!i++)
				choice = !choice;
		}
	};
	print1();
	bool soundEnabled = true;
	while (true) {
		int key = CustomControl::GetUserInputFromConsole();
		if ((key == 3 && choice == 1) || (key == 4 && choice == 0))
			print1();
		else if (key == 6) {
			if (!choice)
				soundEnabled = true;
			else
				soundEnabled = false;
			break;
		}
	}

	if (!soundEnabled) {
		bgSound.setSoundEnabled(false);
		bgSound.playBackgroundSound(false);
	}
	else {
		bgSound.setSoundEnabled(true);
		bgSound.playBackgroundSound(true);
	}

	system("cls");
	MENU::ShowMainMenu();
}
void MENU::DisplayRulesMenu() {
	system("cls");
	UI::loadBackground();
	CustomControl::gotoxy(50, 12);
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, BLACK);
	cout << "FUNCTION KEYS";

	CustomControl::gotoxy(42, 13);
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, YELLOW);
	cout << "L : ";
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, BLUE);
	cout << "Save Game";
	CustomControl::gotoxy(42, 14);
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, YELLOW);
	cout << "P : ";
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, BLUE);
	cout << "Pause Game";
	CustomControl::gotoxy(42, 15);
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, YELLOW);
	cout << "H : ";
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, BLUE);
	cout << "Help";
	CustomControl::gotoxy(42, 16);
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, YELLOW);
	cout << "Esc : ";
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, BLUE);
	cout << "Exit";
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, BLACK);
	CustomControl::gotoxy(42, 17);
	cout << "Rules:";
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, RED);
	CustomControl::gotoxy(45, 18);
	cout << "Cross the road and dodge";
	CustomControl::gotoxy(42, 19);
	cout << "all obstacles (cars & animals)";

	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, GREEN);
	CustomControl::gotoxy(42, 20);
	cout << "Finish 5 levels to win!!!";

	CustomControl::gotoxy(78, 12);
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, BLACK);
	cout << "MOVE";

	CustomControl::gotoxy(75, 14);
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, YELLOW);
	cout << "     W   ";

	CustomControl::gotoxy(75, 15);
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, LIGHT_BLUE);
	cout << "     ^";

	CustomControl::gotoxy(75, 16);
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, YELLOW);
	cout << " A ";

	CustomControl::gotoxy(78, 16);
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, LIGHT_BLUE);
	cout << "<   >";

	CustomControl::gotoxy(80, 16);
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, RED);
	cout << "O";

	CustomControl::gotoxy(84, 16);
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, YELLOW);
	cout << "D";

	CustomControl::gotoxy(75, 17);
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, LIGHT_BLUE);
	cout << "     v   ";

	CustomControl::gotoxy(75, 18);
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, YELLOW);
	cout << "     S";
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, YELLOW);

	CustomControl::SetConsoleTextColor(BLACK, BLACK);
	char c = 219;
	for (int i = 12; i < 21; i++) {
		CustomControl::gotoxy(72, i);
		cout << c;
		CustomControl::gotoxy(88, i);
		cout << c;
	}

	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, GRAY);
	CustomControl::gotoxy(46, 22);
	cout << "Press any keys to go back to menu";

	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, BRIGHT_WHITE);
	CustomControl::gotoxy(44, 23);
	system("pause");
	system("cls");
	MENU::ShowMainMenu();
}




void MENU::startGame() {
	CGAME g(_EASY);
	g.SetUpGame();
	g.startGame();
}
void MENU::loadExistingGame() {
	CGAME g;
	g.loadExistingGame();
}