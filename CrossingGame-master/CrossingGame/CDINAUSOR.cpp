#include "CDINAUSOR.h"

CDINAUSOR::CDINAUSOR(CPOINT pos) : CVEHICLE(pos) {

    shape = new char* [DINO_HEIGHT];
    for (int i = 0; i < DINO_HEIGHT; i++)
        shape[i] = new char[DINO_WIDTH];

    for (int i = 0; i < DINO_HEIGHT; i++)
        for (int j = 0; j < DINO_WIDTH; j++)
            shape[i][j] = ' ';
    // Draw head
    shape[0][1] = '(';
    shape[0][2] = '`';
    shape[0][3] = '~';
    shape[0][4] = '~';
    shape[0][5] = ')';

    shape[1][1] = '//';
    shape[1][2] = '>';
    shape[1][4] = '>';

    shape[2][0] = '//';
    shape[2][2] = ')';
    shape[2][4] = ')';
}

CDINAUSOR::CDINAUSOR() {
    /*
          (o>
       \\-//)
        \_/_)
         _|_
    */
    shape = new char* [DINO_HEIGHT];
    for (int i = 0; i < DINO_HEIGHT; i++)
        shape[i] = new char[DINO_WIDTH];

    for (int i = 0; i < DINO_HEIGHT; i++)
        for (int j = 0; j < DINO_WIDTH; j++)
            shape[i][j] = ' ';

    // Draw head
    shape[0][1] = '(';
    shape[0][2] = '`';
    shape[0][3] = '~';
    shape[0][4] = '~';
    shape[0][5] = ')';

    shape[1][1] = '//';
    shape[1][2] = '>';
    shape[1][4] = '>';

    shape[2][0] = '//';
    shape[2][2] = ')';
    shape[2][4] = ')';
}

CDINAUSOR::~CDINAUSOR() {
    for (int i = 0; i < 4; i++)
        delete[] shape[i];

    delete[] shape;
}

char** CDINAUSOR::returnShape() {
    return shape;
}

int CDINAUSOR::getCharacterHeight() {
    return DINO_HEIGHT;
}

int CDINAUSOR::getCharacterWidth() {
    return DINO_WIDTH;
}

int CDINAUSOR::inGameWidth() {
    return 5;
}