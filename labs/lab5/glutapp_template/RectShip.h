#pragma once

#include "Rect.h"

class RectShip: public Rect{

public:
    RectShip(float, float, float, float, float, float, float);

    void newdraw();

    void shooting();
};