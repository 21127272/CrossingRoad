#include "CBIRD.h"

CBIRD::CBIRD(CPOINT pos) : CVEHICLE(pos) {
    /*
          (o>
       \\-//)
        \_/_)
         _|_
    */
    shape = new char* [BIRD_HEIGHT];
    for (int i = 0; i < BIRD_HEIGHT; i++)
        shape[i] = new char[BIRD_WIDTH];

    for (int i = 0; i < BIRD_HEIGHT; i++)
        for (int j = 0; j < BIRD_WIDTH; j++)
            shape[i][j] = ' ';

    // Draw head
    shape[1][0] = '/';
    shape[1][1] = '^';
    shape[1][2] = 'v';
    shape[1][3] = '^';
    shape[1][4] = '\\';
}

CBIRD::CBIRD() {
    /*
          (o>
       \\-//)
        \_/_)
         _|_
    */
    shape = new char* [BIRD_HEIGHT];
    for (int i = 0; i < BIRD_HEIGHT; i++)
        shape[i] = new char[BIRD_WIDTH];

    for (int i = 0; i < BIRD_HEIGHT; i++)
        for (int j = 0; j < BIRD_WIDTH; j++)
            shape[i][j] = ' ';

    // Draw head
    shape[1][0] = '/';
    shape[1][1] = '^';
    shape[1][2] = 'v';
    shape[1][3] = '^';
    shape[1][4] = '\\';
}

CBIRD::~CBIRD() {
    for (int i = 0; i < 4; i++)
        delete[] shape[i];

    delete[] shape;
}

char** CBIRD::returnShape() {
    return shape;
}

int CBIRD::getCharacterHeight() {
    return BIRD_HEIGHT;
}

int CBIRD::getCharacterWidth() {
    return BIRD_WIDTH;
}

int CBIRD::inGameWidth() {
    return 3;
}
