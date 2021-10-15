#pragma once

#include <deque>
#include "RectShip.h"

class Spaceship{
    std::deque<RectShip*> ship;
    std::deque<RectShip*> enemy;
    std::deque<RectShip*> bullet;
public:
    Spaceship();

    void drawship();
    void drawenemy();

    void up();
    void down();
    void left();
    void right();

    void shoot();
    void shooting();
    void collision();
    void killed();
};