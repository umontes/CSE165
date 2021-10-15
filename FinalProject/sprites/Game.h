#pragma once

#include "TexRect.h"
#include "Player.h"
#include "Obstacle.h"

class Game{
    Player player;
    Obstacle obstacle;
    Rect* space;
    TexRect* _gameover;
public:
    bool dead;

    Game();

    void gameDraw();

    void keypress(unsigned char);

    void collision();

    ~Game();
};