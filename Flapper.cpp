#include "Flapper.h" 
#include "raylib.h"
#include <string>
#include <iostream>



Flappy::Flappy() {
	radius = 15;
	renk = YELLOW;
	konum_x = 400;
	konum_y = 400;
	jump = 10;
	t = 0;
}

void Flappy::drawFlappy() const{
	DrawCircle(konum_x, konum_y, radius, renk);
}


bool Flappy::Check_Key() {

	if (GetKeyPressed() == 32)
	{
		return true;
	}
	else
		return false;



}


void Flappy::movement() {


	if (Check_Key())
	{	//time lazim
		konum_y -= jump * g * (-1);
		t = 1;
	}
	else
	{
		
		t+=GetFrameTime();
		konum_y -= 0.5 * g * (t*t);//h=1/2 g t^2	
	}



}


void Flappy::check_Border() {
	if ((konum_y + radius) >= 600)
		konum_y = 585;
	else if ((konum_y - radius) <= 0)
		konum_y = 15;
}



World::World() {
	t_pipe = 0;
	pipe_Generation();

}

void World::Update()
{
	t_pipe += GetFrameTime();
	if (t_pipe >= 1.3){
		pipe_Generation();
		t_pipe = 0;
	}

	pipe_Movement();
	pipe_Deletion();


}

void World::draw_pipe() {
	pipe_up_it = pipe_up_List.begin();
	pipe_down_it = pipe_down_List.begin();


	while ( pipe_up_it != pipe_up_List.end() && pipe_down_it != pipe_down_List.end()) {
		DrawRectangle(pipe_up_it->x, pipe_up_it->y, pipe_up_it->width, pipe_up_it->height, GREEN);
		DrawRectangle(pipe_down_it->x, pipe_down_it->y, pipe_down_it->width, pipe_down_it->height, GREEN);
		
	
		++pipe_up_it;
		++pipe_down_it;
	
	}
}

void World::pipe_Generation() {
	width = 40;



	//pipe up iicin
	pipe_up_X = 800;
	pipe_up_Y = 0;
	pipe_up_height = GetRandomValue(50, 250);
	
	
	pipe_up = {
		pipe_up_X,
		pipe_up_Y,
		width,
		pipe_up_height
	};
	
	pipe_up_List.push_back(pipe_up);

	
	
	
	//pipe down icin
	pipe_down_X = 800;
	pipe_down_Y = pipe_up_height + 100;//100 ; aradaki bosluk
	pipe_down_height = screenHeight - pipe_down_Y;
	pipe_down = {
		pipe_down_X,
		pipe_down_Y,
		width,
		pipe_down_height
	};
	
	pipe_down_List.push_back(pipe_down);
	

}

void World::pipe_Movement() {


	for(auto& pipe1: pipe_up_List){
	pipe1.x += pipe_x_movement;
	}
	for (auto& pipe2 : pipe_down_List) {
	pipe2.x += pipe_x_movement;
	}
	

}

void World::pipe_Deletion() {

	if (!pipe_up_List.empty() && !pipe_down_List.empty()) {
		if (pipe_up_List.front().x + pipe_up_List.front().width < 0) {
			pipe_up_List.pop_front();
			pipe_down_List.pop_front();
		}
	}
}