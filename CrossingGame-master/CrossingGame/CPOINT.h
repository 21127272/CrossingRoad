#ifndef CPOINT_H_INCLUDED
#define CPOINT_H_INCLUDED

class CPOINT {
	int x, y;
public:
	void setX(int);
	void setY(int);
	void setXY(int, int);
	int getX();
	int getY();
	CPOINT();
	CPOINT(int, int);
};

#endif