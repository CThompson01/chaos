#include "../global.h"

int title_render() {
	return 0;
}

int title_update() {
	return 0;
}

#define render title_render
#define update title_update
enum Screen title_screen(Font defaultFont) {
	// Init title screen
	enum Screen next_screen = CLOSE_GAME;
	char* options[] = {"Play", "Options", "Exit"};
	int selected_option = 0;
	int len_of_options = (sizeof(options) / sizeof(options[0]));

	// Get rid of this later
	int options_block_size = GetScreenHeight()/3;
	int individual_option_size = options_block_size/len_of_options;
	int title_offset_y = 20 + (options_block_size/2);
	int title_offset_x = MeasureTextEx(defaultFont, "Chaos", options_block_size - 40, 0).x/2;
	int options_block_offset = options_block_size + (options_block_size/2);
	int middle_screen = (GetScreenWidth()/2);
	int size_offset;

	// Run title screen
	while (!WindowShouldClose()) {
		// Render
		BeginDrawing();
		ClearBackground(BLACK);

		DrawTextEx(defaultFont, "Chaos", (Vector2) {middle_screen-title_offset_x, title_offset_y}, options_block_size - 40, 0, RED);
		for (int i = 0; i < len_of_options; i++) {
			size_offset = MeasureTextEx(defaultFont, options[i], individual_option_size-20, 0).x/2;
			if (i == selected_option) {
				DrawTextEx(defaultFont, options[i], (Vector2) {middle_screen-size_offset, options_block_offset + (i*(individual_option_size + 10))}, individual_option_size - 20, 0, BLUE);
			} else {
				DrawTextEx(defaultFont, options[i], (Vector2) {middle_screen-size_offset, options_block_offset + (i*(individual_option_size + 10))}, individual_option_size - 20, 0, WHITE);
			}
		}
			
		EndDrawing();
		
		// Update
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