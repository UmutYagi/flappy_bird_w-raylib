#include "Flapper.h" v
#include "raylib.h"
#include <string>
#include <vector>
#include <iostream>
#include <math.h>


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


