#include "CLINE.h"

CLINE::CLINE(int curLine, bool direction, string type, int spacing, int numberOfObj) {
	int left = 6, right = 66;
	this->currentRow = curLine;
	this->space = spacing;
	this->direction = direction;
	CPOINT pos;
	CVEHICLE* obj;
	for (int i = 0; i < numberOfObj; i++) {
		pos.setX(6 + i * spacing);
		pos.setY(6 + 4 * curLine);
		if (type == "bird") {
			obj = new CBIRD(pos);
		}
		if (type == "car") {
			obj = new CCAR(pos);
		}
		if (type == "dino") {
			obj = new CDINAUSOR(pos);
		}
		if (type == "truck") {
			obj = new CTRUCK(pos);
		}
		this->lineData.push_back(obj);
	}
}
/////////////////////

void CLINE::changeLight(bool light) {
	this->greenLight = light;
}

bool CLINE::getLight() {
	return this->greenLight;
}

void CLINE::setSpeed(int _x) {
	this->speed = _x;
}


void CLINE::printObject(CPOINT pos, char** shape, int height, int width) {
	int x = pos.getX();
	int y = pos.getY();
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (x + j < 6 || x + j > 68)
				continue;
			mtx.lock();
			CustomControl::SetConsoleTextColor(BRIGHT_WHITE, BLACK);
			CustomControl::gotoxy(x + j, y + i);
			cout << shape[i][j];
			mtx.unlock();
		}
	}
}

void CLINE::deleteObject(CPOINT pos, char** shape, int height, int width) {
	int x = pos.getX();
	int y = pos.getY();
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (x + j < 6 || x + j > 68)
				continue;
			mtx.lock();
			CustomControl::gotoxy(x + j, y + i);
			cout << " ";
			mtx.unlock();
		}
	}
}


void CLINE::check(CVEHICLE*& obj) {
	if (obj->getX() < -25 && this->direction == 1) {
		obj->newPosition(70, obj->getY());
		return;
	}
	if (obj->getX() > 70 && this->direction == 0) {
		obj->newPosition(-25, obj->getY());
		return;
	}
}

void CLINE::nextMove(CPEOPLE p, bool& isRun) {
	for (int i{}; i < lineData.size(); i++) {
		deleteObject(lineData[i]->getPos(), lineData[i]->returnShape(), lineData[i]->getCharacterHeight(), lineData[i]->getCharacterWidth());
		if (this->direction)
			lineData[i]->updatePosition(-(this->speed), 0);
		else
			lineData[i]->updatePosition(this->speed, 0);
		printObject(lineData[i]->getPos(), lineData[i]->returnShape(), lineData[i]->getCharacterHeight(), lineData[i]->getCharacterWidth());
		check(lineData[i]);
		if (p.checkCollision(lineData[i]))
		{
			isRun = false;
			return;
		}
	}
}

vector<CVEHICLE*> CLINE::getData() {
	return this->lineData;
}

//void CLINE::stillContainObject