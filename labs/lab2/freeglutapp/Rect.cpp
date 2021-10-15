#include "Rect.h"
#include <math.h>

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
	red = 0.4;
	green = 0.4;
	blue = 0.4;

	w = 0.2;
	h = 0.2;

	selected_x = false;
	selected_o = false;
}

Rect::Rect(float x, float y, float w, float h){
	this->x = x;
	this->y = y;

	red = 0.4;
	green = 0.4;
	blue = 0.4;

	this->w = w;
	this->h = h;
	selected_x = false;
	selected_o = false;
}

Rect::Rect(float x, float y, float w, float h, float red, float green, float blue){
	this->x = x;
	this->y = y;

	this->red = red;
	this->green = green;
	this->blue = blue;

	this->w = w;
	this->h = h;

	selected_x = false;
	selected_o = false;
}

void Rect::draw(){
	// draws an O
	if (selected_o){

		glColor3f(0,1,0);
		glPointSize(2);
		glBegin(GL_POINTS);

		float theta = 0;
		float inc = M_PI/500;
		for (theta; theta < 2*M_PI; theta += inc){
			glVertex2f(cos(theta)*0.32+(x+w/2), sin(theta)*0.32+(y-h/2));
		}

		glEnd();

		glColor3f(red, green ,blue);
		glBegin(GL_POLYGON);

		glVertex2f(x, y);
		glVertex2f(x+w, y);
		glVertex2f(x+w, y-h);
		glVertex2f(x, y-h);

		glEnd();

	}

	// draws an X
	else if (selected_x){
		glColor3f(0,1,0);
		glLineWidth(2);
		glBegin(GL_LINES);

		glVertex2f(x,y);
		glVertex2f(x+w, y-h);

		glVertex2f(x+w,y);
		glVertex2f(x, y-h);

		glEnd();

		glColor3f(red, green ,blue);
		glBegin(GL_POLYGON);

		glVertex2f(x, y);
		glVertex2f(x+w, y);
		glVertex2f(x+w, y-h);
		glVertex2f(x, y-h);

		glEnd();
	}

	// keeps the background color of each square
	else{
		glColor3f(red, green, blue);
		glBegin(GL_POLYGON);

		glVertex2f(x, y);
		glVertex2f(x+w, y);
		glVertex2f(x+w, y-h);
		glVertex2f(x, y-h);

		glEnd();
	}
}

bool Rect::contains(float x, float y){
	return (x > this->x) && (x < this->x + this->w) && (y < this->y) && (y > this->y - this->h);
}

bool Rect::select_x(){
	selected_x = true;
}

bool Rect::select_o(){
	selected_o = true;
}
