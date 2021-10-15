#include "Paintapp.h"

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

Paintapp::Paintapp(){
    red = 0;
    green = 0;
    blue = 0;

    eraser = false;
    color = false;

    button.push_back(new Button(-0.95, 0.8, 0.1, 0.1, 1, 0, 0));    //red button
    button.push_back(new Button(-0.95, 0.6, 0.1, 0.1, 0, 1, 0));    //green button
    button.push_back(new Button(-0.95, 0.4, 0.1, 0.1, 0, 0, 1));    //blue button
    button.push_back(new Button(-0.71, 0.96, 0.18, 0.07, 0.5, 0.5, 0.5));    //paint button
    button.push_back(new Button(-0.96, 0.96, 0.2, 0.07, 0.5, 0.5, 0.5));    //eraser button
}

Paintapp::Paintapp(float x, float y, float w, float h, float r, float g, float b): x(x), y(y), w(w), h(h), r(r), g(g), b(b){
    red = 0;
    green = 0;
    blue = 0;

    eraser = false;
    color = false;
}

void Paintapp::Point(float mx, float my){

    for (std::deque<Button*>::iterator i = button.begin(); i != button.end(); i++){
        (*i)->deselect();
    }

    for (std::deque<Button*>::iterator i = button.begin(); i != button.end(); i++){
        if ((*i)->contains(mx,my) && i == button.begin()){
            (*i)->select();
            color = true;
            red = 1;
            green = 0;
            blue = 0;
        }
        else if ((*i)->contains(mx,my) && i == button.begin()+1){
            (*i)->select();
            color = true;
            red = 0;
            green = 1;
            blue = 0;
        }
        else if ((*i)->contains(mx,my) && i == button.begin()+2){
            (*i)->select();
            color = true;
            red = 0;
            green = 0;
            blue = 1;
        }
        else if ((*i)->contains(mx,my) && i == button.begin()+3){
            (*i)->select();
            color = true;
            eraser = false;
        }
        else if ((*i)->contains(mx,my) && i == button.begin()+4){
            (*i)->select();
            color = true;
            red = 0;
            green = 0;
            blue = 0;
            eraser = true;
        }
    }

    if (color == true && red == 1){
        points.push_front(new Paint(mx, my, 10, h, 1, 0, 0));
    }
    else if (color == true && green == 1){
        points.push_front(new Paint(mx, my, 10, h, 0, 1, 0));
    }
    else if (color == true && blue == 1){
        points.push_front(new Paint(mx, my, 10, h, 0, 0, 1));
    }
    else if (color == true && eraser == true){
        points.push_front(new Paint(mx, my, 18, h, 1, 1, 1));
    }
    else if (color == true && eraser == false){
        points.push_front(new Paint(mx, my, 10, h, 1, 0, 0));
    }

}

void Paintapp::draw(){
	for(int i = 0; i < points.size(); i++){ //draws the points when painting/erasing
		points[i]->draw();
	}

    for (int i = 0; i < button.size(); i++){    //draws the buttons for the colors and the paint/erase
        button[i]->draw();
    }
}