#include <iostream>
#include "App.h"

App::App(int argc, char** argv, int width, int height, const char* title): GlutApp(argc, argv, width, height, title){
    game = new Game();
} 

void App::draw() const {
    game->gameDraw();
}

void App::keyDown(unsigned char key, float x, float y){
    if (key == 27){
        exit(0);
    }
    game->keypress(key);
    redraw();
}

App::~App(){   
    delete game;
    std::cout << "Exiting..." << std::endl;
}

// Press the w, a, s, d keys to move up, left, down, and right respectivley.
// Avoid the falling rocks or it's game over.