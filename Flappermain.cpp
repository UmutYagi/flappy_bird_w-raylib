#include "Flapper.h"


using namespace std;

int main() {
	World world;
	World pipe;
	Flappy bird;
	InitWindow(world.screenWidth, world.screenHeight, "Flappy Bird");
	InitAudioDevice();
	SetTargetFPS(30);


	while (!WindowShouldClose())
	{
		world.Update();

		BeginDrawing();
		ClearBackground(BLACK);

		pipe.draw_pipe();


		bird.drawFlappy();
		bird.movement();
		bird.check_Border();

		
		EndDrawing();
	}
	return 0;
}