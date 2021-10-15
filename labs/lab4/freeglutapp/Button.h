#ifndef BUTTON_H
#define BUTTON_H

struct Button{

    float x;
    float y;
    float w;
    float h;

    float r;
	float g;
	float b;

    bool selected;

    Button(float x, float y, float w, float h, float r, float g, float b);

    void draw();

    bool contains(float x, float y);

    bool select();
    bool deselect();

};

#endif