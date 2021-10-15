#include "Paint.h"
#include <deque>
#include <math.h>

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

Paint::Paint(float x, float y, float w, float h, float r, float g, float b): x(x), y(y), w(w), h(h), r(r), g(g), b(b){

}

void Paint::draw(){
    // glColor3f(r, g, b);
    // glPointSize(10+w);

    // glBegin(GL_POINTS);
    // glVertex2f(x, y);
    // glEnd();

    glColor3f(r,g,b);    //painting with circles
    glPointSize(w);
    glBegin(GL_POINTS);
    float theta = 0;
    float inc = M_PI/100;
    for (theta; theta <= 2*M_PI; theta += inc){
        glVertex2f(cos(theta)*0.005+(x), sin(theta)*0.005+(y));
    }
    glEnd();
}