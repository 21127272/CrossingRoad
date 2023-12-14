#pragma once

class CPOSITION {
private:
	int x, y;
public:
	CPOSITION() {
		x = 0;
		y = 0;
	}
	~CPOSITION() {}
	void setPos(int _x, int _y) {
		this->x = _x;
		this->y = _y;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
};