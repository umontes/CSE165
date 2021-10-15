#include "Rect.h"

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

Rect::Rect(){
	x = 0;
	y = 0;

	red = 1;
	green = 0;
	blue = 0;

	w = 0.2;
	h = 0.2;

	selected = false;
	cselected = false;

	dx = 0;
    dy = 0;

}

Rect::Rect(float x, float y, float w, float h){
	this->x = x;
	this->y = y;

	red = 1;
	green = 0;
	blue = 0;

	this->w = w;
	this->h = h;

	selected = false;
	cselected = false;

	dx = 0;
    dy = 0;
}

Rect::Rect(float x, float y, float w, float h, float red, float green, float blue){
	this->x = x;
	this->y = y;

	this->red = red;
	this->green = green;
	this->blue = blue;

	this->w = w;
	this->h = h;

	selected = false;
	cselected = false;

	dx = 0;
    dy = 0;	
}

bool Rect::contains(float x, float y){
	return (x > this->x) && (x < this->x + this->w) && (y < this->y) && (y > this->y - this->h);
}

void Rect::draw(){ 
	if (selected){

		glColor3f(1,1,1);
		glBegin(GL_LINES);

		glVertex2f(x, y);
		glVertex2f(x+w, y);

		glVertex2f(x+w, y);
		glVertex2f(x+w, y-h);

		glVertex2f(x+w, y-h);
		glVertex2f(x, y-h);

		glVertex2f(x, y-h);
		glVertex2f(x, y);

		glEnd();

		glColor3f(red, green, blue);
		glBegin(GL_POLYGON);

		glVertex2f(x, y);
		glVertex2f(x+w, y);
		glVertex2f(x+w, y-h);
		glVertex2f(x, y-h);

		glEnd();
	}

	glColor3f(red, green, blue);
	glBegin(GL_POLYGON);

	glVertex2f(x, y);
	glVertex2f(x+w, y);
	glVertex2f(x+w, y-h);
	glVertex2f(x, y-h);

	glEnd();
}

bool Rect::select(){
	selected = true;
}

bool Rect::deselect(){
	selected = false;
}

bool Rect::corner(float x, float y){
	return (x > (this->x + this->y) + 0.09) && (x < this->x + this->w) && (y < (this->y - this->h) + 0.09) && (y > this->y - this->h);
}

bool Rect::corner_select(){
	cselected = true;
}

void Rect::set(float mx, float my){
    dx = abs(x - mx);
    dy = abs(y - my);
}