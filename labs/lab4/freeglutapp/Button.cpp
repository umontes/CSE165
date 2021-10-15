#include "Button.h"
#include <deque>

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

Button::Button(float x, float y, float w, float h, float r, float g, float b): x(x), y(y), w(w), h(h), r(r), g(g), b(b){
    selected = false;
}

void Button::draw(){

    if (selected){
        glColor3f(0,0,0);
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

        glColor3f(r,g,b);
        glBegin(GL_POLYGON);
        glVertex2f(x,y);
        glVertex2f(x,y-h);
        glVertex2f(x+w,y-h);
        glVertex2f(x+w,y);
        glEnd();
    }

    glColor3f(r,g,b);
    glBegin(GL_POLYGON);
    glVertex2f(x,y);
    glVertex2f(x,y-h);
    glVertex2f(x+w,y-h);
    glVertex2f(x+w,y);
    glEnd();
}

bool Button::contains(float x , float y){
    return (x > this->x) && (x < this->x + this->w) && (y < this->y) && (y > this->y - this->h);
}

bool Button::select(){
    selected = true;
}

bool Button::deselect(){
    selected = false;
}