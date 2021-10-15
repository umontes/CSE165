#include <iostream>
#include "Spaceship.h"

Spaceship::Spaceship(){
    ship.push_front(new RectShip(-0.1, -0.6, 0.3, 0.2, 1, 1, 1));
	enemy.push_front(new RectShip(-0.1, 0.6, 0.3, 0.2, 1, 0, 0));
}

void Spaceship::drawship(){
	for (int i = 0; i < bullet.size(); i++){
        bullet[i]->newdraw();
        bullet[i]->shooting();
        killed();
    }
	// for (std::deque<RectShip*>::iterator i = bullet.begin(); i != bullet.end(); i++){
    //     (*i)->newdraw();
    //     (*i)->shooting();
    //     killed();
    // }
	ship[0]->newdraw();
}

void Spaceship::drawenemy(){
	enemy[0]->newdraw();
}

void Spaceship::up(){
	ship[0]->setY(ship[0]->getY() + 0.1);
}
void Spaceship::down(){
	ship[0]->setY(ship[0]->getY() - 0.1);
}
void Spaceship::left(){
	ship[0]->setX(ship[0]->getX() - 0.1);
}
void Spaceship::right(){
	ship[0]->setX(ship[0]->getX() + 0.1);
}

void Spaceship::shoot(){
	std::cout << "shoot" << std::endl;
	bullet.push_front(new RectShip(ship[0]->getX() + (ship[0]->getW()/2) - 0.025, ship[0]->getY() + 0.15, 0.05, 0.1, 1, 0, 0 ));
	shooting();
}

void Spaceship::shooting(){
	bullet[0]->setY(bullet[0]->getY() + 0.05);
}

void Spaceship::collision(){
	if ((ship[0]->getY() >= enemy[0]->getY() - enemy[0]->getH()) 
			&& (ship[0]->getY() - ship[0]->getH() <= enemy[0]->getY() + 0.01)
			&& (ship[0]->getX() <= enemy[0]->getX() + enemy[0]->getW())
			&& (ship[0]->getX() + ship[0]->getW() >= enemy[0]->getX() + 0.01)){
		std::cout << "GAME OVER" << std::endl;
		exit(0);
	}
}

void Spaceship::killed(){
	for (std::deque<RectShip*>::iterator i = bullet.begin(); i != bullet.end(); i++){
		if (((*i)->getY() >= enemy[0]->getY() - enemy[0]->getH()) 
			&& ((*i)->getY() - (*i)->getH() <= enemy[0]->getY() + 0.01)
			&& ((*i)->getX() <= enemy[0]->getX() + enemy[0]->getW())
			&& ((*i)->getX() + (*i)->getW() >= enemy[0]->getX() + 0.01)){
				std::cout << "YOU WIN" << std::endl;
				exit(0);
		}
	}
}