#include "raylib.h"
#include "../global.h"

int title_render() {
	return 0;
}

int title_update() {
	return 0;
}

#define render title_render
#define update title_update
enum Screen title_screen() {
	// Init title screen
	enum Screen next_screen = CLOSE_GAME;
	char* options[] = {"Play", "Options", "Exit"};
	int selected_option = 0;
	int len_of_options = (sizeof(options) / sizeof(options[0]));

	// Run title screen
	while (!WindowShouldClose()) {
		// Render
		BeginDrawing();
		ClearBackground(BLACK);

		for (int i = 0; i < len_of_options; i++) {
			if (i == selected_option) {
				DrawText(options[i], 200, 200 + (i*30), 20, BLUE);
			} else {
				DrawText(options[i], 200, 200 + (i*30), 20, WHITE);
			}
		}
			
		EndDrawing();
		
		// Update

		// Take user input
		if (IsKeyPressed(KEY_ENTER)) {
			switch (selected_option) {
				case 0:
					next_screen = GAME;
					break;
				case 1:
					next_screen = OPTIONS;
					break;
				default:
					next_screen = CLOSE_GAME;
					break;
			}
			break;
		}

		if (IsKeyPressed(KEY_UP)) {
			if (selected_option > 0) {
				selected_option -= 1;
			}
		}

		if (IsKeyPressed(KEY_DOWN)) {
			if (selected_option < len_of_options-1) {
				selected_option += 1;
			}
		}
	}
	
	return next_screen;
}
#undef render
#undef update