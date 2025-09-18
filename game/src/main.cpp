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
float x = 500;
float y = 500;
float frequency = 1;
float amplitude = 100;

float speed = 100;
float angle = 30;

//Changes world state
void update()
{
	dt = 1.0f / TARGET_FPS;
	time += dt;

	x = x + (-sin(time * frequency)) * frequency * amplitude * dt;
	y = y + (cos(time * frequency)) * frequency * amplitude * dt;
}

//Display world state
void draw()
{
	BeginDrawing();
	ClearBackground(BLACK);
	DrawText("Joss Moo-Young 123456789", 10, float(GetScreenHeight() - 30), 20, LIGHTGRAY);


	GuiSliderBar(Rectangle{ 10, 15, 1000, 20 }, "", TextFormat("%.2f", time), &time, 0, 240);
	DrawText(TextFormat("T: %6.2f", time), GetScreenWidth() - 140, 10, 30, LIGHTGRAY);


	GuiSliderBar(Rectangle{ 10, 100, 200, 100 }, "", TextFormat("Speed: %.0f", speed), &speed, -100, 1000);
	GuiSliderBar(Rectangle{ 10, 200, 200, 100 }, "", TextFormat("Angle: %.0f", angle), &angle, -180, 180);

	/*DrawCircle(x, y, 70, RED);
	DrawCircle(500 + cos(time * frequency) * amplitude, 500 + sin(time * frequency) * amplitude, 70, GREEN);*/

	Vector2 startPos = {200, GetScreenHeight() - 200};
	Vector2 velocity = {cos(angle * DEG2RAD) * speed, -sin(angle * DEG2RAD) * speed};

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