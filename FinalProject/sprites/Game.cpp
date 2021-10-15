#include <iostream>
#include "Game.h"

Game::Game(){
    space = new TexRect("images/space2.png", -1, 1, 3.2, 2);
    _gameover = new TexRect("images/gameoverScreen.png", -0.8, 0.8, 1.6, 1.6);
    dead = false;
}

void Game::gameDraw(){
    if (!dead){
        space->draw();
        obstacle.drawObstacle();
        player.drawPlayer();
    }
    else if (dead){
        _gameover->draw();
        space->draw();
    }
    collision();
}

void Game::keypress(unsigned char key){
    if (key == 'w'){
        player.up();
        collision();
    }
    if (key == 's'){
        player.down();
        collision();
    }
    if (key == 'a'){
        player.left();
        collision();
    }
    if (key == 'd'){
        player.right();
        collision();
    }
}

void Game::collision(){
    if ((player.playerY() > obstacle.obstacle_1_Y() - obstacle.obstacle_1_H() - 0.02) 
			&& (player.playerY() - player.playerH() < obstacle.obstacle_1_Y() - 0.05)
			&& (player.playerX() < obstacle.obstacle_1_X() + obstacle.obstacle_1_W() - 0.02)
			&& (player.playerX() + player.playerW() > obstacle.obstacle_1_X() - 0.05) ){
        dead = true;
    }
    if ((player.playerY() > obstacle.obstacle_2_Y() - obstacle.obstacle_2_H() - 0.02) 
			&& (player.playerY() - player.playerH() < obstacle.obstacle_2_Y() - 0.05)
			&& (player.playerX() < obstacle.obstacle_2_X() + obstacle.obstacle_2_W() - 0.02)
			&& (player.playerX() + player.playerW() > obstacle.obstacle_2_X() - 0.05) ){
        dead = true;
    }
    if ((player.playerY() > obstacle.obstacle_3_Y() - obstacle.obstacle_3_H() - 0.02) 
			&& (player.playerY() - player.playerH() < obstacle.obstacle_3_Y() - 0.05)
			&& (player.playerX() < obstacle.obstacle_3_X() + obstacle.obstacle_3_W() - 0.02)
			&& (player.playerX() + player.playerW() > obstacle.obstacle_3_X() - 0.05) ){
        dead = true;
    }
    if ((player.playerY() > obstacle.obstacle_4_Y() - obstacle.obstacle_4_H() - 0.02) 
			&& (player.playerY() - player.playerH() < obstacle.obstacle_4_Y() - 0.05)
			&& (player.playerX() < obstacle.obstacle_4_X() + obstacle.obstacle_4_W() - 0.02)
			&& (player.playerX() + player.playerW() > obstacle.obstacle_4_X() - 0.05) ){
        dead = true;
    }
    if ((player.playerY() > obstacle.obstacle_5_Y() - obstacle.obstacle_5_H() - 0.02) 
			&& (player.playerY() - player.playerH() < obstacle.obstacle_5_Y() - 0.05)
			&& (player.playerX() < obstacle.obstacle_5_X() + obstacle.obstacle_5_W() - 0.02)
			&& (player.playerX() + player.playerW() > obstacle.obstacle_5_X() - 0.05) ){
        dead = true;
    }
}

Game::~Game(){
    delete space;
    delete _gameover;
}