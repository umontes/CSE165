#include "Game.h"

Game::Game(){

}

void Game::drawgame(){
    spaceship.drawship();
    enemy.drawenemy();
}

void Game::handle(unsigned char key){
    if (key == 'w'){
        spaceship.up();
    }
    if (key == 's'){
        spaceship.down();
    }
    if (key == 'a'){
        spaceship.left();
    }
    if (key == 'd'){
        spaceship.right();
    }
    if (key == ' '){
        spaceship.shoot();
    }
    spaceship.collision();
}