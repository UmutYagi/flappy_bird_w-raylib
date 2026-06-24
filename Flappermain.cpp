#include "Flapper.h"


using namespace std;

int main() {
	
	InitWindow(800,600, "Flappy Bird");
	//InitAudioDevice();
	SetTargetFPS(30);
	World pipe;
	Flappy bird(pipe);
	int gameOver=1;
	while(!WindowShouldClose){
	while (gameOver==1)
	{
		gameOver = !bird.Check_Death(pipe);

		pipe.Update();

		BeginDrawing();
		ClearBackground(BLACK);

		pipe.draw_pipe();
		bird.check_Border();
	

		bird.drawFlappy();
		bird.movement(pipe); 
		
			
		
		EndDrawing();
	}
	while (gameOver==0) 
	{
			BeginDrawing();
			ClearBackground(WHITE);
			DrawText("GAME OVER", 300, 280, 40, RED);
			EndDrawing();

	}
	}
	
	return 0;
}