/*
This project uses the Raylib framework to provide us functionality for math, graphics, GUI, input etc.
See documentation here: https://www.raylib.com/, and examples here: https://www.raylib.com/examples.html
*/

#include "raylib.h"
#include "raymath.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "game.h"


const unsigned int TARGET_FPS = 50; //frames/second
float dt = 1.0f / TARGET_FPS; //seconds/frame
float time = 0;

float speed = 100;
float angle = 30;

Vector2 position;
Vector2 velocity;
Vector2 gravityAcceleration = { 0, 100 };

//Changes world state
void update()
{
	dt = 1.0f / TARGET_FPS;
	time += dt;


	if (IsKeyPressed(KEY_SPACE))
	{
		position = { 200, (float)GetScreenHeight() - 200 };
		velocity = { (float)cos(angle * DEG2RAD) * speed, (float) - sin(angle * DEG2RAD) * speed};
	}

	//velocity changes position over time. 
	// velocity = displacement/time    therefore     Displacement = velocity * time
	position += velocity * dt;

	//acceleration changes velocity over time
	// accel = deltaV / time    therefore    deltaV = accel * time    where deltaV is a change in velocity
	velocity += gravityAcceleration * dt;
}

//Display world state
void draw()
{
	BeginDrawing();
	ClearBackground(BLACK);
	DrawText("Joss Moo-Young 123456789", 10, float(GetScreenHeight() - 30), 20, LIGHTGRAY);


	GuiSliderBar(Rectangle{ 10, 15, 1000, 20 }, "", TextFormat("%.2f", time), &time, 0, 240);
	DrawText(TextFormat("T: %6.2f", time), GetScreenWidth() - 140, 10, 30, LIGHTGRAY);

	GuiSliderBar(Rectangle{ 10, 60, 200, 20 }, "", TextFormat("Speed: %.0f", speed), &speed, -100, 1000);
	GuiSliderBar(Rectangle{ 10, 90, 200, 20 }, "", TextFormat("Angle: %.0f", angle), &angle, -180, 180);
	GuiSliderBar(Rectangle{ 10, 120, 200, 20 }, "", TextFormat("G: %.0f", gravityAcceleration.y), &gravityAcceleration.y, -600, 600);

	//Draw circle
	DrawCircle(position.x, position.y, 15, RED);


	Vector2 startPos = { 200, GetScreenHeight() - 200 };
	Vector2 velocity = { cos(angle * DEG2RAD) * speed, -sin(angle * DEG2RAD) * speed };
	DrawLineEx(startPos, startPos + velocity, 3, RED);

	EndDrawing();

}

int main()
{
	InitWindow(InitialWidth, InitialHeight, "GAME2005 Joss Moo-Young 123456789");
	SetTargetFPS(TARGET_FPS);

	while (!WindowShouldClose()) // Loops TARGET_FPS times per second
	{
		update();
		draw();
	}

	CloseWindow();
	return 0;
}