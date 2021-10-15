#pragma once

#include "Spaceship.h"

class Game {
    Spaceship spaceship;
    Spaceship enemy;
public:
    Game();

    void drawgame();

    void handle(unsigned char);

};