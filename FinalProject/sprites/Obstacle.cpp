#include <iostream>
#include "Obstacle.h"

static Obstacle* singleton;

void obstacleTimer(int id){
    singleton->_obstacle1->setY(singleton->_obstacle1->getY() - 0.03);

    singleton->_obstacle2->setY(singleton->_obstacle2->getY() - 0.03);
    singleton->_obstacle2->setX(singleton->_obstacle2->getX() - 0.03);

    singleton->_obstacle3->setY(singleton->_obstacle3->getY() - 0.03);
    singleton->_obstacle3->setX(singleton->_obstacle3->getX() + 0.03);   

    singleton->_obstacle4->setY(singleton->_obstacle4->getY() - 0.03);
    singleton->_obstacle4->setX(singleton->_obstacle4->getX() + 0.05);  

    singleton->_obstacle5->setY(singleton->_obstacle5->getY() - 0.01);

    singleton->redraw();

    glutTimerFunc(singleton->obstacleInterval, obstacleTimer, id);
}

Obstacle::Obstacle(){
    _obstacle1 = new Sprite("images/dumbRock_brown.png", 5, 5, 0.0, 0.6, 0.12, 0.12);
    _obstacle2 = new Sprite("images/dumbRock_red.png", 4, 5, 0.4, 0.8, 0.12, 0.12);
    _obstacle3 = new Sprite("images/dumbRock_brown.png", 5, 5, -1.4, 0.8, 0.12, 0.12);
    _obstacle4 = new Sprite("images/dumbRock_red.png", 4, 5, -0.8, 0.8, 0.12, 0.12);
    _obstacle5 = new Sprite("images/dumbRock_red.png", 4, 5, 0.6, 0.8, 0.12, 0.12);

    obstacleInterval = 200;
    singleton = this;
    obstacleTimer(1);
}

void Obstacle::drawObstacle(){
    _obstacle1->draw(0.5);
    _obstacle2->draw(0.5);
    _obstacle3->draw(0.5);
    _obstacle4->draw(0.5);
    _obstacle5->draw(0.5);
}

float Obstacle::obstacle_1_X() const{
    return _obstacle1->getX();
}
float Obstacle::obstacle_1_Y() const{
    return _obstacle1->getY();
}
float Obstacle::obstacle_1_W() const{
    return _obstacle1->getW();
}
float Obstacle::obstacle_1_H() const{
    return _obstacle1->getH();
}


float Obstacle::obstacle_2_X() const{
    return _obstacle2->getX();
}
float Obstacle::obstacle_2_Y() const{
    return _obstacle2->getY();
}
float Obstacle::obstacle_2_W() const{
    return _obstacle2->getW();
}
float Obstacle::obstacle_2_H() const{
    return _obstacle2->getH();
}


float Obstacle::obstacle_3_X() const{
    return _obstacle3->getX();
}
float Obstacle::obstacle_3_Y() const{
    return _obstacle3->getY();
}
float Obstacle::obstacle_3_W() const{
    return _obstacle3->getW();
}
float Obstacle::obstacle_3_H() const{
    return _obstacle3->getH();
}


float Obstacle::obstacle_4_X() const{
    return _obstacle4->getX();
}
float Obstacle::obstacle_4_Y() const{
    return _obstacle4->getY();
}
float Obstacle::obstacle_4_W() const{
    return _obstacle4->getW();
}
float Obstacle::obstacle_4_H() const{
    return _obstacle4->getH();
}

float Obstacle::obstacle_5_X() const{
    return _obstacle5->getX();
}
float Obstacle::obstacle_5_Y() const{
    return _obstacle5->getY();
}
float Obstacle::obstacle_5_W() const{
    return _obstacle5->getW();
}
float Obstacle::obstacle_5_H() const{
    return _obstacle5->getH();
}

Obstacle::~Obstacle(){
    delete _obstacle1;
    delete _obstacle2;
    delete _obstacle3;
    delete _obstacle4;
    delete _obstacle5;

    std::cout << "Deleting sprites..." << std::endl;
}