#include "raylib.h"

int main ()
{
	// Tell the window to use vysnc and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window
	InitWindow(1280, 800, "Chaos");
	
	// Enter the title screen
	title_screen();

	// Cleanup
	CloseWindow();
	return 0;
}

int title_screen() {
	// Init title screen

	// Run title screen
	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(BLACK);
		DrawText("Chaos", 200,200,20,WHITE);
		EndDrawing();
	}
	
	return 0;
}

int game_screen() {
	return 0;
}

int options_screen() {
	return 0;
}