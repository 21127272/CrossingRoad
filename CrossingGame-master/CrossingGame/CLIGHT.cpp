#include "CLIGHT.h"

CLIGHT::CLIGHT() {
	isPlay = true;
	state = true;
	posX = 0;
	posY = 0;
	timer = 0;
}
bool CLIGHT::getisPlay() {
	return isPlay;
}
void CLIGHT::setisPlay(bool play) {
	isPlay = play;
}
bool CLIGHT::isSoundEnabled() {
	return state;
}
void CLIGHT::setSoundEnabled(bool _state) {
	state = _state;
}
void CLIGHT::setTimer(int timer) {
	while (timer && isPlay) {
		spawn_light(posX, posY);
		Sleep(1000);
		timer -= 10;
	}
	this->setSoundEnabled(!state);
}
void CLIGHT::setPos(int x, int y) {
	posX = x;
	posY = y;
}
void CLIGHT::spawn_light(int x, int y) {
	setPos(x, y);
	if (state) {
		//Draw green light.
		mtx.lock();
		CustomControl::SetConsoleTextColor(BRIGHT_WHITE, GREEN);
		CustomControl::gotoxy(x, y + 1);
		cout << TopDot;
		CustomControl::SetConsoleTextColor(BRIGHT_WHITE, GRAY);
		CustomControl::gotoxy(x, y);
		cout << BottomDot;
		mtx.unlock();
	}
	else {
		//Draw red light
		mtx.lock();
		CustomControl::SetConsoleTextColor(BRIGHT_WHITE, RED);
		CustomControl::gotoxy(x, y);
		cout << BottomDot;
		CustomControl::SetConsoleTextColor(BRIGHT_WHITE, GRAY);
		CustomControl::gotoxy(x, y + 1);
		cout << TopDot;
		mtx.unlock();

	}
}