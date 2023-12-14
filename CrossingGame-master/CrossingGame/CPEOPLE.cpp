#include"CPEOPLE.h"

const string people[] = { R"(.-.)", R"(| |)", R"(|_| )" };

int CPEOPLE::getX() {
	return this->pos.getX();
}

int CPEOPLE::getY() {
	return pos.getY();
}

int CPEOPLE::getPlayerScore() {
	return score;
}

int CPEOPLE::getForwardMovement() {
	return forward;
}

int CPEOPLE::getBackwardMovement() {
	return back;
}

int CPEOPLE::getCharacterHeight() {
	return height;
}

int CPEOPLE::getCharacterWidth() {
	return width;
}

void CPEOPLE::updatePlayerScore() {
	if (score < getForwardMovement() - getBackwardMovement())
		this->score++;
}

void CPEOPLE::updatePosition(int x, int y) {
	pos.setXY(x, y);
}

void CPEOPLE::drawCharacter(int x, int y) {
	for (int i = 0; i < 3; i++) {
		mtx.lock();
		CustomControl::SetConsoleTextColor(BRIGHT_WHITE, LIGHT_BLUE);
		CustomControl::gotoxy(x, y + i);
		cout << people[i];
		mtx.unlock();
	}
}

void CPEOPLE::deleteCharacter(int x, int y) {
	for (int i = 0; i < 3; i++) {
		mtx.lock();
		CustomControl::gotoxy(x, y + i);
		cout << "   ";
		mtx.unlock();
	}
}

void CPEOPLE::goUp(int& y) {
	if (y == 6)
		return;
	y -= 4;
	forward++;
	updatePlayerScore();
}

void CPEOPLE::goLeft(int& x) {
	if (x == 6)
		return;
	x -= 2;
}

void CPEOPLE::goRight(int&x) {
	if (x + 3 == 69)
		return;
	x += 2;
}

void CPEOPLE::goDown(int&y) {
	if (y + 3 == 29)
		return;
	y += 4;
	back++;
}

bool CPEOPLE::checkCollision(CVEHICLE* Object) {
	int playerX = this->getX();
	int playerY = this->getY();
	int objectWidth = Object->inGameWidth();
	int objectX = Object->getX();

	if (playerY == Object->getY()) {
		if ((playerX >= objectX && playerX <= objectX + objectWidth - 1) ||
			(playerX + 2 >= objectX && playerX + 2 <= objectX + objectWidth - 1)) {
			return true;
		}
	}
	return false;
}

bool CPEOPLE::checkFinishLine() {
	if (pos.getY() == 6)
		return true;
	return false;
}