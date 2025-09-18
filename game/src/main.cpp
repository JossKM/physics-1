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
float angle = 0;

//Changes world state
void update()
{
	dt = 1.0f / TARGET_FPS;
	time += dt;
}

//Display world state
void draw()
{
	BeginDrawing();
	ClearBackground(BLACK);
	DrawText("Joss Moo-Young 123456789", 10, float(GetScreenHeight() - 30), 20, LIGHTGRAY);


	GuiSliderBar(Rectangle{ 10, 15, 1000, 20 }, "", TextFormat("%.2f", time), &time, 0, 240);

	GuiSliderBar(Rectangle{ 10, 40, 500, 30 }, "Speed", TextFormat("Speed: %.0f", speed), &speed, -1000, 1000);

	GuiSliderBar(Rectangle{ 10, 80, 500, 30 }, "Angle", TextFormat("Angle: %.0f Degrees", angle), &angle, -180, 180);

	DrawText(TextFormat("T: %6.2f", time), GetScreenWidth() - 140, 10, 30, LIGHTGRAY);

	Vector2 startPos = {100, GetScreenHeight() - 100};

	Vector2 velocity = {speed * cos(angle * DEG2RAD), -speed * sin(angle * DEG2RAD)};

	DrawLineEx(startPos, startPos + velocity, 3, RED);


	//DrawCircle(x, y, 70, RED);
	//DrawCircle(500 + cos(time * frequency) * amplitude, 500 + sin(time * frequency) * amplitude, 70, GREEN);

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