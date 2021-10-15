#pragma once

#include "Sprite.h"

class Player{
    Sprite* _player;
public:
    Player();

    void drawPlayer();

    void up();
    void down();
    void left();
    void right();    

    float playerX() const;
    float playerY() const;
    float playerW() const;
    float playerH() const;

    ~Player();
};