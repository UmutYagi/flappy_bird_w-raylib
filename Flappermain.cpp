#include "Flapper.h"


using namespace std;

int main() {
	
	Flappy bird;
	InitWindow(800, 600, "Flappy Bird");
	InitAudioDevice();
	SetTargetFPS(30);


	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);


		bird.drawFlappy();
		bird.movement();

		
		
		
		EndDrawing();
	}
	return 0;
}