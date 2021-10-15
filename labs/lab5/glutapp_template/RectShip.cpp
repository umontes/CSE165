#include "RectShip.h"

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

RectShip::RectShip(float x, float y, float w, float h, float red, float green, float blue): Rect(x, y, w, h, red, green, blue){
    
}

void RectShip::newdraw(){
    glColor3f(red, green, blue);
	glBegin(GL_POLYGON);

	glVertex2f(x, y);
	glVertex2f(x+w, y);
	glVertex2f(x+w, y-h);
	glVertex2f(x, y-h);

	glEnd();
}

void RectShip::shooting(){
	for (int i = 0; i < 10; i++){
		glColor3f(red, green, blue);
		glBegin(GL_POLYGON);

		glVertex2f(x+0.01, y+0.01);
		glVertex2f(x+w+0.01, y+0.01);
		glVertex2f(x+w+0.01, y-h+0.01);
		glVertex2f(x+0.01, y-h+0.01);

		glEnd();
	}
}