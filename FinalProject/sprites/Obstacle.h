#pragma once

#include "Sprite.h"
#include "Rect.h"

class Obstacle: public Rect{
    Sprite* _obstacle1;
    Sprite* _obstacle2;
    Sprite* _obstacle3;
    Sprite* _obstacle4;
    Sprite* _obstacle5;

    unsigned int obstacleInterval;
public:
    Obstacle();

    void drawObstacle();

    friend void obstacleTimer(int);

    float obstacle_1_X() const;
    float obstacle_1_Y() const;
    float obstacle_1_W() const;
    float obstacle_1_H() const;

    float obstacle_2_X() const;
    float obstacle_2_Y() const;
    float obstacle_2_W() const;
    float obstacle_2_H() const;

    float obstacle_3_X() const;
    float obstacle_3_Y() const;
    float obstacle_3_W() const;
    float obstacle_3_H() const;

    float obstacle_4_X() const;
    float obstacle_4_Y() const;
    float obstacle_4_W() const;
    float obstacle_4_H() const;

    float obstacle_5_X() const;
    float obstacle_5_Y() const;
    float obstacle_5_W() const;
    float obstacle_5_H() const;

    ~Obstacle();
};