#include "../global.h"

int game_render() {
	return 0;
}

int game_update() {
	return 0;
}

#define render title_render
#define update title_update
enum Screen game_screen() {
	// Init game screen
	enum Screen next_screen = CLOSE_GAME;

	// Run game screen
	while (!WindowShouldClose()) {
		// Render
		BeginDrawing();
		ClearBackground(BLACK);
		DrawText("Game", 200, 200, 20, WHITE);
		EndDrawing();
		
		// Update
		if (IsKeyPressed(KEY_ESCAPE)) {
			next_screen = TITLE;
			break;
		}
	}
	
	return next_screen;
}
#undef render
#undef update