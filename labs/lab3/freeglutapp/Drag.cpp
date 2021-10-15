#include "Drag.h"
#include <deque>
#include <math.h>

Drag::Drag(){

    x = 0;
    y = 0;
    w = 0;
    h = 0;

    squares.push_back(new Rect(-0.9, 0.9, 0.5, 0.5, 1, 0, 0));
	squares.push_back(new Rect(-0.5, 0.3, 0.5, 0.5, 0, 0, 1));
    squares.push_back(new Rect(0.2, 0.9, 0.5, 0.5, 0, 1, 0));
}

void Drag::draw(){
    for (int i = 0; i < squares.size(); i++){
	    squares[i]->draw();
	}
}

bool Drag::clicked(float mx, float my, float s){
    if (s == 0){
        for (std::deque<Rect*>::iterator i = squares.begin(); i != squares.end(); i++){
			    (*i)->deselect();
                (*i)->cselected = false;
	    }
	    for (std::deque<Rect*>::iterator i = squares.begin(); i != squares.end(); i++){
            if ((*i)->corner(mx,my)){
                (*i)->corner_select();
                (*i)->select();
            }
		    else if ((*i)->contains(mx, my)){
                    Rect* temp = *i;
			        (*i)->select();
                    (*i)->set(mx,my);
                    squares.erase(i);
			        squares.push_front(temp);
			        break;
		    }
	    }
    }
}

bool Drag::move(float mx, float my){

    if (squares[0]->contains(mx,my)){
		squares[0]->x = mx - (squares[0]->dx);
		squares[0]->y = my + (squares[0]->dy);
    }

}

bool Drag::resize(float mx, float my){
    if (squares[0]->cselected == true){
        squares[0]->w -= squares[0]->x + squares[0]->w - mx;
        squares[0]->h -= my - (squares[0]->y - squares[0]->h); 
    }
}
