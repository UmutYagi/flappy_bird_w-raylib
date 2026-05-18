
#ifndef FLAPPER_H
#define FLAPPER_H



#include "raylib.h"
#include <list>



class World {
private:
	
	std::list<Rectangle> pipe_up_List;
	std::list<Rectangle> pipe_down_List;
	std::list<Rectangle>::iterator pipe_up_it;
	std::list<Rectangle>::iterator pipe_down_it;
	//pipe decl
	float pipe_up_height;
	float width;
	float pipe_up_Y;
	float pipe_up_X;
	float pipe_down_height;
	float pipe_down_Y;
	float pipe_down_X;
	float pipe_x_movement=-8;


protected:

	float g = ( - 4);

	//pipe declaretion;
	Rectangle pipe_up = {
		pipe_up_X,
		pipe_up_Y,//random but not 0
		width,
		pipe_up_height//random
	};
	
	Rectangle pipe_down = {
		pipe_down_X,
		pipe_down_Y,//pipe_up_height -100
		width,
		pipe_down_height//should be the diffirence of the wideness and the up pipe's height
	};

public:
	World();
	int screenHeight = 600;
	int screenWidth = 800;
	float t_pipe;
	
	void Update();
	void draw_pipe() ;
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
	void check_Border();


};

#endif // !FLAPPER.H

