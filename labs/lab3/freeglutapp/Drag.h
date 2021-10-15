#ifndef DRAG_H
#define DRAG_H

#include "Rect.h"
#include <deque>

struct Drag{
    std::deque<Rect*> squares;

    float x;
    float y;
    float w; 
    float h;

    float old_mx;
    float old_my;

    Drag();

    void draw();

    bool clicked(float x, float y, float s);

    bool move(float x, float y);

    bool resize(float x, float y);

};

#endif