#include "Sprite.h"

Sprite::Sprite(const char* filename, int rows, int cols, float x, float y, float w, float h): TexRect(filename, x, y, w, h){
    this->rows = rows;
    this->cols = cols;

    xinc = 1.0 / cols;
    yinc = 1.0 / rows;

    curr_row = 1;
    curr_col = 1;

    left = xinc * (curr_col - 1);
    right = xinc * curr_col;
    top = 1 - yinc * (curr_row - 1);
    bottom = 1 - yinc * curr_row;

    done = false;

}

void Sprite::draw(float z = 0){
    glBindTexture( GL_TEXTURE_2D, texture_id );
    glEnable(GL_TEXTURE_2D);
    
    glBegin(GL_QUADS);
    glColor4f(1, 1, 1, 1);
    glTexCoord2f(left, bottom);
    glVertex3f(x, y - h, z);
    
    glTexCoord2f(left, top);
    glVertex3f(x, y, z);
    
    glTexCoord2f(right, top);
    glVertex3f(x+w, y, z);
    
    glTexCoord2f(right, bottom);
    glVertex3f(x+w, y - h, z);
    
    glEnd();
    
    glDisable(GL_TEXTURE_2D);
}

bool Sprite::isDone () const {
    return done;
}

void Sprite::reset(){
    curr_row = 1;
    curr_col = 1;
    done = false;
}

void Sprite::advance(){
    if (!done){
        if (curr_col < cols){
            curr_col++;
        }
        else{
            if (curr_row < rows){
                curr_col = 1;
                curr_row++;
            }
            else{
                done = true;
                curr_row = 1;
                curr_col = 1;
            }
            
        }
        left = xinc * (curr_col - 1);
        right = xinc * curr_col;
        top = 1 - yinc * (curr_row - 1);
        bottom = 1 - yinc * curr_row;

    }
}

Sprite::~Sprite(){

}
