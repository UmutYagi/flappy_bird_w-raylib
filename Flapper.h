
#ifndef FLAPPER_H
#define FLAPPER_H


#include <list>
#include <vector>
#include "raylib.h"



class World {
private:
	
	float upHeight;
	float width;
	float upY;
	float upX;
	float downHeight;
	float downY;
	float downX;
	float pipe_x_movement=-8;


protected:
	std::vector<Rectangle> pipe_up_List;
	std::vector<Rectangle> pipe_down_List;
	std::vector<Rectangle>::iterator pipe_up_it;
	std::vector<Rectangle>::iterator pipe_down_it;

	float g = ( - 4);
	

    //pipe declaretion;
	Rectangle pipe_up = {
		upX,
		upY,//random but not 0
		width,
		upHeight//random
	};
	
	Rectangle pipe_down = {
		downX,
		downY,//pipe_up_height -100
		width,
		downHeight//should be the diffirence of the wideness and the up pipe's height
	};

public:
	World();
	int screenHeight = 600;
	int screenWidth = 800;
	float t_pipe;
	int skor=0;
	void Update();
	void draw_pipe() ;
	void pipe_Generation();
	void pipe_Deletion();
	void pipe_Movement();
	void skorbord();
	const std::vector<Rectangle>& get_pipe_up_List() const {
		return pipe_up_List; 
	}

	const std::vector<Rectangle>& get_pipe_down_List() const { 
		return pipe_down_List; 
	}
	const float get_g() const {
		return g;
	}
};




class Flappy {
	World& world;
	
private:
	float radius;
	Color renk;
	float konum_x;
	float konum_y;
	Vector2 konumlar = {
		konum_x,
		konum_y
	};
	int jump;
	float t;
	bool Check_Key();//done

public:
	Flappy(World& w);
	bool Check_Death(World& world);//Collision Detect , Check after Drawing
	void movement(World& world);//done
	void drawFlappy() const;//done
	void check_Border();//done


};

#endif // !FLAPPER.H

