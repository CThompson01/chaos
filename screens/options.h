#include "raylib.h"
#include "../global.h"

int options_render() {
	return 0;
}

int options_update() {
	return 0;
}

#define render title_render
#define update title_update
enum Screen options_screen() {
	// Init options screen
	enum Screen next_screen = CLOSE_GAME;

	// Run options screen
	while (!WindowShouldClose()) {
		// Render
		BeginDrawing();
		ClearBackground(BLACK);
		DrawText("Options", 200, 200, 20, WHITE);
		EndDrawing();
		
		// Update

		// Take user input
		
	}
	
	return next_screen;
}
#undef render
#undef update