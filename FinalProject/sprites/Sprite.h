#pragma once

#include "TexRect.h"

class Sprite: public TexRect{
	int rows;
	int cols;

	float xinc;
	float yinc;

	int curr_row;
	int curr_col;

	float left;
	float right;
	float top;
	float bottom;

	bool done;

public:
	Sprite(const char* filename, int rows, int cols, float x, float y, float w, float h);

	void draw(float);
	
	bool isDone () const;

	void reset();

	void advance();

	~Sprite();
};
