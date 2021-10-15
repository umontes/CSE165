#include <iostream>
#include "Player.h"

Player::Player(){
    _player = new Sprite("images/HammerTurtle.png", 3, 7, 0.0, -0.6, 0.2, 0.2);
}

void Player::drawPlayer(){
    _player->draw(0.5);
}

void Player::up(){
    _player->setY(_player->getY() + 0.045);
}
void Player::down(){
    _player->setY(_player->getY() - 0.045);
}
void Player::left(){
    _player->setX(_player->getX() - 0.045);
}
void Player::right(){
    _player->setX(_player->getX() + 0.045);
}    

float Player::playerX() const{
    return _player->getX();
}
float Player::playerY() const{
    return _player->getY();
}
float Player::playerW() const{
    return _player->getW();
}
float Player::playerH() const{
    return _player->getH();
}

Player::~Player(){
    delete _player;
    std::cout << "Deleting player..." << std::endl;
}