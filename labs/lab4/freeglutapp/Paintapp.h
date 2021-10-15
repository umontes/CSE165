#ifndef PAINTAPP_H
#define PAINTAPP_H

#include "Button.h"
#include "Paint.h"
#include <deque>

struct Paintapp{
    
    std::deque<Button*> button;
    std::deque<Paint*> points;

    float x;
    float y;
    float w;
    float h;

    float r;
	float g; 
	float b;

    int red;
    int green;
    int blue;

    bool eraser;
    bool color;

    Paintapp();

    Paintapp(float x, float y, float w, float h, float r, float g, float b);

	void draw();

    void Point(float x, float y);

};

#endif