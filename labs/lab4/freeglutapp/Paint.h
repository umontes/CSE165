#ifndef PAINT_H
#define PAINT_H

struct Paint{

    float x;
    float y;
    float w;
    float h;

    float r;
	float g;
	float b;

    Paint(float x, float y, float w, float h, float r, float g, float b);

    void draw();

};

#endif