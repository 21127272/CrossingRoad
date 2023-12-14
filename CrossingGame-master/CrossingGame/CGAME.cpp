#include "CGAME.h";

CGAME::CGAME() : currentLevel(1), isRun(true), isPause(false), isSave(false), playerScore(0) {}

CGAME::CGAME(int level) : currentLevel(level), isRun(true), isPause(false), isSave(false), playerScore(0) {}

int CGAME::getCurrentLevel() {
	return this->currentLevel;
}

string CGAME::getPlayerName() {
	return playerName;
}
string CGAME::getPlayerID() {
	return playerID;
}
string CGAME::getClassName() {
	return className;
}
int CGAME::getPlayerScore() {
	return playerScore;
}
int CGAME::getLevel() {
	return currentLevel;
}
void CGAME::setPlayerInfo(string playerName, string playerID, string className, int playerScore, int currentLevel) {
	this->playerName = playerName;
	this->playerID = playerID;
	this->className = className;
	this->playerScore = playerScore;
	this->currentLevel = currentLevel;
}
void CGAME::renderLight() {
	while (gameLight.getisPlay()) {
		if (gameLight.isSoundEnabled()) {
			gameLight.spawn_light(4, 13);
			gameLight.spawn_light(70, 21);
			gameLight.setTimer(50);
		}
		else {
			gameLight.spawn_light(4, 13);
			gameLight.spawn_light(70, 21);
			gameLight.setTimer(30);
		}
	}
}
void CGAME::SetUpGame() {
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, YELLOW);
	system("cls");
	CustomControl::gotoxy(0, 0);
	UI::loadBackground();
	CustomControl::ToggleCursorVisibility(true);
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, RED);
	CustomControl::gotoxy(38, 12);
	cout << "Please enter your name shortly, under 10 characters!";

	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, LIGHT_BLUE);
	CustomControl::gotoxy(48, 15);
	cout << "Enter your name:  ";
	getline(cin, playerName);
	CustomControl::gotoxy(48, 17);
	cout << "Enter your ID:  ";
	getline(cin, playerID);
	CustomControl::gotoxy(48, 19);
	cout << "Enter your class:  ";
	getline(cin, className);
	CustomControl::ToggleCursorVisibility(false);
}
void CGAME::startGame() {
	UI::displayInterface();
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, BLUE);
	CustomControl::gotoxy(85, 7);
	if (playerName.size() != 0)
		cout << "Player's name: " << playerName;
	else {
		playerName = "unknown";
		cout << "Player's name: " << playerName;
	}
	CustomControl::gotoxy(85, 9);
	if (playerID.size() != 0)
		cout << "Student's ID: " << playerID;
	else {
		playerID = "unknown";
		cout << "Student's ID: " << playerID;
	}
	CustomControl::gotoxy(85, 11);
	if (className.size() != 0)
		cout << "Class: " << className;
	else {
		className = "unknown";
		cout << "Class: " << className;
	}
	thread gameLight;
	thread people;

	thread mainGame([&] {renderObject(gameLight, people); });

	mainGame.join();
	gameLight.join();
	people.join();
}
void CGAME::winGame() {
	gameSound.playBackgroundSound(false);
	const char winText[] = R"(
		 __          _______ _   _ ______ _____   __          _______ _   _ ______ _____  
		 \ \        / /_   _| \ | |  ____|  __ \  \ \        / /_   _| \ | |  ____|  __ \ 
		  \ \  /\  / /  | | |  \| | |__  | |__) |  \ \  /\  / /  | | |  \| | |__  | |__) |
		   \ \/  \/ /   | | | . ` |  __| |  _  /    \ \/  \/ /   | | | . ` |  __| |  _  / 
		    \  /\  /   _| |_| |\  | |____| | \ \     \  /\  /   _| |_| |\  | |____| | \ \ 
		   __\/_ \/   |_____|_| \_|______|_|  \_\  _ _\/  \/   |_____|_| \_|______|_|  \_\            
)";
	system("cls");
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, RED);
	cout << winText;
	gameSound.playWinSound();
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, BLACK);
	UI::displayRectangle(45, 13, 35, 8);
	UI::displayRectangle(48, 18, 7, 2);
	UI::displayRectangle(71, 18, 6, 2);

	CustomControl::gotoxy(49, 15);
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, GREEN);
	Sound bgSound;
	cout << "Do you want to play again?";
	string str[2] = { "Yes", "No" };
	int left[] = { 46,51,58,69,74,80 }, word[] = { 32,32,175,174 }, color[] = { BLACK, GREEN }, top = 19;
	bool choice = 1;
	auto print1 = [&]()
	{
		int i = 0;
		while (i < 2)
		{
			CustomControl::SetConsoleTextColor(BRIGHT_WHITE, color[i]);
			CustomControl::gotoxy(left[choice * 3], top);        putchar(word[i * 2]);
			CustomControl::gotoxy(left[choice * 3 + 1], top);    cout << str[choice];
			CustomControl::gotoxy(left[choice * 3 + 2], top);    putchar(word[i * 2 + 1]);
			if (!i++)
				choice = !choice;
		}
	};
	print1();
	while (true)
	{
		int key = CustomControl::GetUserInputFromConsole();
		if ((key == 3 && choice == 1) || (key == 4 && choice == 0))
			print1();
		else if (key == 6)
		{
			if (!choice) {
				isRun = true;
				gameSound.playSuccessSound();
				gameSound.playBackgroundSound(true);
				MENU mMenu;
				mMenu.ShowMainMenu();
			}
			else {
				gameSound.playSuccessSound();
				isRun = false;
			}
			break;
		}
		else
			gameSound.playPlayerMoveSound();
	}
}
void CGAME::playGame(CLINE* line2, CLINE* line3, CLINE* line4, CLINE* line5) {
	vector<CVEHICLE*> line;

	while (isRun) {
		mtx.lock();
		CustomControl::SetConsoleTextColor(BRIGHT_WHITE, RED);
		CustomControl::gotoxy(10, 1);
		UI::displayLevel(currentLevel);
		CustomControl::SetConsoleTextColor(BRIGHT_WHITE, BLACK);
		UI::displayRectangle(90, 0, 10, 2);
		CustomControl::gotoxy(92, 1);
		cout << "SCORE: " << playerScore + people.getPlayerScore();
		mtx.unlock();
		int x = people.getX();
		int y = people.getY();

		if (people.checkFinishLine())
		{
			people.updatePosition(36, 26);
			currentLevel++;
		}
		else
		{
			people.drawCharacter(people.getX(), people.getY());
			if (isPause) {
				mtx.lock();
				PauseGame();
				mtx.unlock();
			}
			switch (CustomControl::GetUserInputFromConsole()) {
			case 1:  //ESC
				isRun = false;
				gameLight.setisPlay(false);
				gameLight.setSoundEnabled(false);
				break;
			case 2: //UP
			{
				people.deleteCharacter(x, y);
				people.goUp(y);
				break;
			}
			case 3: //LEFT
			{
				people.deleteCharacter(x, y);
				people.goLeft(x);
				break;
			}
			case 4: //RIGHT
			{
				people.deleteCharacter(x, y);
				people.goRight(x);
				break;
			}
			case 5: //DOWN
			{
				people.deleteCharacter(x, y);
				people.goDown(y);
				break;
			}
			case 7: //PAUSE CGAME
				isPause = true;
				break;

			case 8: // SAVE CGAME
				isSave = true;
				break;
			case 9: // HELP
				
				mtx.lock();
				printHelp();
				mtx.unlock();
				break;
			}
			people.updatePosition(x, y);
		}
		if (isSave) {
			mtx.lock();
			SaveGame();
			mtx.unlock();
		}
		if (isPause) {
			mtx.lock();
			PauseGame();
			mtx.unlock();
		}
	}
}
void CGAME::endGame(thread* game) {
	system("cls");
	isRun = false;
	game->join();
	UI::displayGBScr();
}

void CGAME::SaveGame() {
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, BLACK);
	UI::displayRectangle(79, 20, 33, 8);
	UI::displayRectangle(80, 23, 31, 2);
	CustomControl::gotoxy(89, 22);
	CustomControl::ToggleCursorVisibility(true);
	cout << "Enter a filename";
	CustomControl::gotoxy(81, 24);
	cin >> filename;
	CustomControl::ToggleCursorVisibility(false);
	filename = "./gameData/" + filename + ".txt";

	fstream saveFile("listFile.txt", ios::app);
	saveFile << filename << "\n";
	saveFile.close();

	if (_mkdir("./gameData") == -1) {
		CustomControl::SetConsoleTextColor(BRIGHT_WHITE, RED);
		CustomControl::gotoxy(82, 26);
		cerr << " Error : " << strerror(errno) << endl;
	}
	fstream fs(filename, ios::app);
	if (isSave) {
		fs << "Player's name: " << playerName << '\n' << "ID: " << playerID << '\n' << "Class: " <<
			className << '\n' << "Level: " << currentLevel << "\n" << "Score: " << people.getPlayerScore() << '\n';
		fs << "Position: " << people.getX() << "," << people.getY() << '\n';
	}
	fs.close();
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, GREEN);
	CustomControl::gotoxy(82, 26);
	cout << "----Save game successfully----";
	Sleep(1000);
	// Clear up save game board
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, BRIGHT_WHITE);
	for (int i = 79; i < 114; i++)
	{
		for (int j = 20; j < 29; j++) {
			CustomControl::gotoxy(i, j);
			cout << " ";
		}
	}
	isSave = false;
	gameLight.setisPlay(true);
}
void CGAME::loadExistingGame() {
	system("cls");
	UI::loadBackground();

	ifstream fi("listFile.txt");
	string tmp;
	while (!fi.eof()) {
		getline(fi, tmp);
		saveFileList.push_back(tmp);
	}
	fi.close();

	if (saveFileList.empty()) {
		CustomControl::gotoxy(47, 11);
		CustomControl::SetConsoleTextColor(BRIGHT_WHITE, BLUE);
		cout << "No load game" << '\n';
		return;
	}
	int selectedIndex = 13, maxIndex = saveFileList.size() - 1 + 13, prevIndex = 13;
	bool found = false;
	string name;
	while (true) {
		if (found)
			break;

		CustomControl::gotoxy(47, 11);
		CustomControl::SetConsoleTextColor(BRIGHT_WHITE, BLUE);
		cout << "Choose your saving game to load!";

		for (int i = saveFileList.size() - 2; i >= 0; i--) {
			if (i >= saveFileList.size() - 9) {
				CustomControl::SetConsoleTextColor(BRIGHT_WHITE, BLACK);
				CustomControl::gotoxy(61, 11 + saveFileList.size() - i);
				name = saveFileList[i].substr(11, saveFileList[i].size() - 15);
				cout << name << "       ";
			}
		}

		CustomControl::SetConsoleTextColor(BRIGHT_WHITE, GRAY);
		CustomControl::gotoxy(46, 22);
		cout << "Press any keys to go back to the menu";

		CustomControl::gotoxy(58, selectedIndex);
		CustomControl::SetConsoleTextColor(BRIGHT_WHITE, RED);
		cout << (char)175;
		CustomControl::gotoxy(61, selectedIndex);
		name = saveFileList[saveFileList.size() - 2].substr(11, saveFileList[saveFileList.size() - 2].size() - 15);
		cout << name << "       ";

		while (true) {
			char s = CustomControl::GetUserInputFromConsole();

			if (s == 2 || s == 5) {
				selectedIndex += (s == 2) ? -1 : 1;

				// Handle bounds and list scrolling
				if (selectedIndex < 13) {
					selectedIndex = maxIndex;
				}
				else if (selectedIndex > maxIndex)
					selectedIndex = 0;

				// Draw the list based on the current index
				for (int i = saveFileList.size() - 2; i >= 0; i--) {
					if (i >= saveFileList.size() - 9) {
						CustomControl::SetConsoleTextColor(BRIGHT_WHITE, BLACK);
						CustomControl::gotoxy(61, 11 + saveFileList.size() - i);
						if (selectedIndex - 13 != i) {
							name = saveFileList[i].substr(11, saveFileList[i].size() - 15);
							cout << name << "       ";
						}
					}
				}

				// Highlight the selected item
				CustomControl::gotoxy(61, selectedIndex);
				CustomControl::SetConsoleTextColor(BRIGHT_WHITE, RED);
				name = saveFileList[saveFileList.size() - (selectedIndex - 13) - 2].substr(11, saveFileList[saveFileList.size() - (selectedIndex - 13) - 2].size() - 15);
				cout << name << "       ";
			}

			// Handle enter key
			if (s == 6) {
				selectedIndex = saveFileList.size() - (selectedIndex - 13) - 2;
				found = true;
				break;
			}

			// Handle other keys
			if (s != 2 && s != 5 && s != 6) {
				MENU mMenu;
				mMenu.ShowMainMenu();
			}

			// Update cursor position
			CustomControl::gotoxy(58, prevIndex);
			cout << "  ";
			CustomControl::gotoxy(58, selectedIndex);
			CustomControl::SetConsoleTextColor(BRIGHT_WHITE, RED);
			cout << (char)175;

			prevIndex = selectedIndex;
		}
	}

	fstream readFile(saveFileList[selectedIndex], ios::in);
	int posX{}, posY{};
	while (!readFile.eof()) {
		getline(readFile, tmp, ':');
		readFile.get();
		getline(readFile, playerName);

		getline(readFile, tmp, ':');
		readFile.get();
		getline(readFile, playerID);

		getline(readFile, tmp, ':');
		readFile.get();
		getline(readFile, className);
		readFile.get();

		getline(readFile, tmp, ':');
		readFile.get();
		readFile >> currentLevel;
		readFile.ignore();

		getline(readFile, tmp, ':');
		readFile.get();
		readFile >> playerScore;
		readFile.ignore();

		getline(readFile, tmp, ':');
		readFile.get();
		readFile >> posX;
		readFile.ignore();

		readFile >> posY;
		readFile.ignore();
	}
	readFile.close();

	isRun = true;
	people.updatePosition(posX, posY);
	isPause = true;
	startGame();
}

void CGAME::printHelp() {
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, BLACK);
	UI::displayRectangle(79, 20, 33, 8);

	CustomControl::gotoxy(90, 21);
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, RED);
	cout << "Instructions";

	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, BLACK);
	CustomControl::gotoxy(80, 22);	cout << "- Cross the road and dodge all";
	CustomControl::gotoxy(80, 23); cout << "obstacles (cars & animals)";
	CustomControl::gotoxy(80, 24); cout << "- Use W, A, S, D to move";

	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, BLUE);
	CustomControl::gotoxy(80, 25); cout << "- Finish 5 currentLevels to win!!!";

	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, GREEN);
	CustomControl::gotoxy(91, 27);
	putchar(175);
	CustomControl::gotoxy(93, 27);
	cout << "Close";
	CustomControl::gotoxy(99, 27);
	putchar(174);
	char ch = _getch();
	// Clear up HELP board
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, BRIGHT_WHITE);
	for (int i = 79; i < 114; i++)
	{
		for (int j = 20; j < 29; j++) {
			CustomControl::gotoxy(i, j);
			cout << " ";
		}
	}

	gameLight.setisPlay(true);
}
void CGAME::PauseGame() {
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, RED);
	CustomControl::gotoxy(79, 20); cout << R"(  _____       _    _  _____ ______ )";
	CustomControl::gotoxy(79, 21); cout << R"( |  __ \ /\  | |  | |/ ____|  ____|)";
	CustomControl::gotoxy(79, 22); cout << R"( | |__) /  \ | |  | | (___ | |__	 )";
	CustomControl::gotoxy(79, 23); cout << R"( |  ___/ /\ \| |  | |\___ \|  __|  )";
	CustomControl::gotoxy(79, 24); cout << R"( | |  / ____ \ |__| |____) | |____ )";
	CustomControl::gotoxy(79, 25); cout << R"( |_| /_/    \_\____/|_____/|______|)";

	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, GREEN);
	CustomControl::gotoxy(88, 27);
	cout << "Press any key to Resume";
	char ch = _getch();

	// Clear up Pause board
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, BRIGHT_WHITE);
	for (int i = 79; i < 114; i++)
	{
		for (int j = 20; j < 29; j++) {
			CustomControl::gotoxy(i, j);
			cout << " ";
		}
	}
	Sleep(10);
	isPause = false;
	gameLight.setisPlay(true);
}
void CGAME::renderObject(thread& tL, thread& tO) {
	int dx = -6, dy = 6;
	int _dx = 58;
	int ObjSpace;
	CLINE* line2 = new CLINE(1, 1, "bird", 15, 4);
	CLINE* line3 = new CLINE(2, 1, "truck", 20, 3);
	CLINE* line4 = new CLINE(3, 0, "dino", 20, 1);
	CLINE* line5 = new CLINE(4, 0, "car", 30, 2);
	vector<CVEHICLE*> line;
	tL = thread([this] {renderLight(); });
	tO = thread([&] {playGame(line2, line3, line4, line5); });

	while (isRun) {
		line2->setSpeed(getCurrentLevel());
		line3->setSpeed(getCurrentLevel());
		line4->setSpeed(getCurrentLevel());
		line5->setSpeed(getCurrentLevel());

		//line2->changeLight(gameLight.isSoundEnabled());
		line3->changeLight(gameLight.isSoundEnabled());
		//line4->changeLight(gameLight.isSoundEnabled());
		line5->changeLight(gameLight.isSoundEnabled());


		line2->nextMove(people, isRun);

		if (line3->getLight()) {
			line3->nextMove(people, isRun);
		}


		line4->nextMove(people, isRun);


		if (line5->getLight()) {
			line5->nextMove(people, isRun);
		}

		mtx.lock();
		line = line2->getData();
		for (int i = 0; i < line.size(); i++) {
			if (people.checkCollision(line[i])) {
				//cout << "Line 2";
				gameLight.setisPlay(false);
				gameLight.setSoundEnabled(false);
				isRun = false;
				break;
			}
		}

		line = line3->getData();
		for (int i{}; i < line.size(); i++) {
			if (people.checkCollision(line[i])) {
				//cout << "Line 3";
				gameLight.setisPlay(false);
				gameLight.setSoundEnabled(false);
				isRun = false;
				break;
			}
		}

		line = line4->getData();
		for (int i{}; i < line.size(); i++) {
			if (people.checkCollision(line[i])) {
				gameLight.setisPlay(false);
				gameLight.setSoundEnabled(false);
				isRun = false;
				break;
			}
		}

		line = line5->getData();
		for (int i{}; i < line.size(); i++) {
			if (people.checkCollision(line[i])) {
				//cout << line[i]->getX() << "|" << people.getX();
				//Sleep(5000);
				gameLight.setisPlay(false);
				gameLight.setSoundEnabled(false);
				isRun = false;
				break;
			}
		}
		if (currentLevel == 6) {
			gameLight.setisPlay(false);
			gameLight.setSoundEnabled(false);
			isRun = false;
			winGame();
		}
		mtx.unlock();
		Sleep(50);
	}
	if (!isRun && currentLevel != 6) {
		loseGame();
	}
	UI::displayGBScr();
	tL.join();
	tO.join();
}
void CGAME::loseGame() {
	gameSound.playBackgroundSound(false);
	const char loseText[] = R"(
		  /$$$$$$   /$$$$$$  /$$      /$$ /$$$$$$$$        /$$$$$$  /$$    /$$ /$$$$$$$$ /$$$$$$$ 
		 /$$__  $$ /$$__  $$| $$$    /$$$| $$_____/       /$$__  $$| $$   | $$| $$_____/| $$__  $$
		| $$  \__/| $$  \ $$| $$$$  /$$$$| $$            | $$  \ $$| $$   | $$| $$      | $$  \ $$
		| $$ /$$$$| $$$$$$$$| $$ $$/$$ $$| $$$$$         | $$  | $$|  $$ / $$/| $$$$$   | $$$$$$$/
		| $$|_  $$| $$__  $$| $$  $$$| $$| $$__/         | $$  | $$ \  $$ $$/ | $$__/   | $$__  $$
		| $$  \ $$| $$  | $$| $$\  $ | $$| $$            | $$  | $$  \  $$$/  | $$      | $$  \ $$
		|  $$$$$$/| $$  | $$| $$ \/  | $$| $$$$$$$$      |  $$$$$$/   \  $/   | $$$$$$$$| $$  | $$
		 \______/ |__/  |__/|__/     |__/|________/       \______/     \_/    |________/|__/  |__/              
)";
	system("cls");
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, RED);
	cout << loseText;
	gameSound.playLoseSound();
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, BLACK);
	UI::displayRectangle(45, 13, 35, 8);
	UI::displayRectangle(48, 18, 7, 2);
	UI::displayRectangle(71, 18, 6, 2);

	CustomControl::gotoxy(49, 15);
	CustomControl::SetConsoleTextColor(BRIGHT_WHITE, GREEN);
	Sound bgSound;
	cout << "Do you want to play again?";
	string str[2] = { "Yes", "No" };
	int left[] = { 46,51,58,69,74,80 }, word[] = { 32,32,175,174 }, color[] = { BLACK, GREEN }, top = 19;
	bool choice = 1;
	auto print1 = [&]()
	{
		int i = 0;
		while (i < 2)
		{
			CustomControl::SetConsoleTextColor(BRIGHT_WHITE, color[i]);
			CustomControl::gotoxy(left[choice * 3], top);        putchar(word[i * 2]);
			CustomControl::gotoxy(left[choice * 3 + 1], top);    cout << str[choice];
			CustomControl::gotoxy(left[choice * 3 + 2], top);    putchar(word[i * 2 + 1]);
			if (!i++)
				choice = !choice;
		}
	};
	print1();
	while (true)
	{
		int key = CustomControl::GetUserInputFromConsole();
		if ((key == 3 && choice == 1) || (key == 4 && choice == 0))
			print1();
		else if (key == 6)
		{
			if (!choice) {
				isRun = true;
				gameSound.playSuccessSound();
				gameSound.playBackgroundSound(true);
				MENU mMenu;
				mMenu.ShowMainMenu();
			}
			else {
				gameSound.playSuccessSound();
				isRun = false;
			}
			break;
		}
		else
			gameSound.playPlayerMoveSound();
	}
}