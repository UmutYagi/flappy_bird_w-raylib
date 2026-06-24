#include "Flapper.h" 
#include "raylib.h"
#include <string>
#include <iostream>



Flappy::Flappy(World& world) {
	
	radius = 15;
	renk = YELLOW;
	konum_x = 400;
	konum_y = 400;
	jump = 10;
	t = 0;
	konumlar = {
		konum_x,
		konum_y
	};
	
}

bool Flappy::Check_Death(World& world)
{
	
	for (int i = 0;i < world.get_pipe_up_List().size();i++) {

	if (CheckCollisionCircleRec(konumlar, radius, world.get_pipe_up_List()[i] ) )
	{
		return 1;

	}
	if (CheckCollisionCircleRec(konumlar, radius, world.get_pipe_down_List()[i] ) )
	{
		return 1;

	}
	}
	return 0;

	
}

void Flappy::drawFlappy() const{
	DrawCircleV(konumlar, radius, renk);

}

bool Flappy::Check_Key() {

	if (GetKeyPressed() == 32)
	{
		return true;
	}
	else
		return false;



}

void Flappy::movement(World& world) {


	if (Check_Key())
	{	
		konumlar.y -= jump * world.get_g() * (-1);
		
		t = 1;
	}
	else
	{
		
		t+=GetFrameTime();
		konumlar.y -= 0.5 * world.get_g() * (t*t);//h=1/2 g t^2	
		
	}


}

void Flappy::check_Border() {
	if ((konumlar.y + radius) >= 600)
	{
		konumlar.y = 585;
		t = 1;
	}
	else if ((konumlar.y - radius) <= 0)
	{
	konumlar.y = 15;
	}

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
		++pipe_up_it;

		DrawRectangle(pipe_down_it->x, pipe_down_it->y, pipe_down_it->width, pipe_down_it->height, GREEN);
		++pipe_down_it;
		
	
	
	}
}

void World::pipe_Generation() {
	width = 40;

	//pipe up iicin
	upX = 800;
	upY = 0;
	upHeight = GetRandomValue(50, 250);
	
	
	pipe_up = {
		upX,
		upY,
		width,
		upHeight
	};
	
	pipe_up_List.push_back(pipe_up);

	
	
	
	//pipe down icin
	downX = 800;
	downY = upHeight + 100;//100 ; aradaki bosluk
	downHeight = screenHeight - downY;
	pipe_down = {
		downX,
		downY,
		width,
		downHeight
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
			pipe_up_List.erase(pipe_up_List.begin());
			pipe_down_List.erase(pipe_down_List.begin());
		}
	}
}
