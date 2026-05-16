#pragma once
#ifndef FLAPPER.H
#define FLAPPER
#endif // !FLAPPER.H


#include "raylib.h"

class World {
private:
	float pipe_up_height;
	float pipe_down_height;
	float pipe_up_Y;
	float pipe_down_Y;

protected:

	float g = ( - 4);

	//pipe declaretion;
	Rectangle pipe_up = {
		800,
		pipe_up_Y,//random but not 0
		40,
		pipe_up_height//random
	};

	Rectangle pipe_down = {
		800,
		pipe_down_Y,//random but not 400
		40,
		pipe_down_height// should be the diffirence of the wideness and the up pipe's height
	};

public:
	void draw_pipe() const;
	void pipe_Generation();
	void pipe_Deletion();
	void pipe_Movement();

};



class Flappy: public World {
	
private:
	float radius;
	Color renk;
	float konum_x;
	float konum_y;
	int jump;
	float t;
	void Check_Death();//Collision Detect , Check after Drawing
	bool Check_Key();

public:
	Flappy();
	void movement();
	void drawFlappy() const;



};

