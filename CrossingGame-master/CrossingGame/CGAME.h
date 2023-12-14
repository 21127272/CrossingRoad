#ifndef CGAME_H_INCLUDED
#define CGAME_H_INCLUDED

#include "Header.h"
#include "CPEOPLE.h"
#include "UI.h"
#include "CLINE.h"
#include "MENU.h"

class CGAME {
private:
	string playerName, playerID, className;
	string filename;
	vector<string> saveFileList;
	int currentLevel;
	bool isRun;
	bool isPause;
	bool isSave;
	CPEOPLE people;
	CLIGHT gameLight;
	Sound gameSound;
	int playerScore;
public:
	string getPlayerName();
	string getPlayerID();
	string getClassName();

	int getPlayerScore();
	int getLevel();

	void setPlayerInfo(string name, string id, string clss, int _playerScore, int _currentLevel);
	CGAME();
	CGAME(int);
	int getCurrentLevel();
	void SetUpGame();
	void startGame();
	void endGame(thread*);
	void SaveGame();
	void PauseGame();
	void loadExistingGame();
	void playGame(CLINE*, CLINE*, CLINE*, CLINE*);
	void printHelp();

	void renderLight();
	void renderObject(thread&, thread&);

	void winGame();
	void loseGame();
};
#endif