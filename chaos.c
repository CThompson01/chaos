#include <stddef.h>
#include "raylib.h"
#include "global.h"
#include "screens/title.h"
#include "screens/game.h"
#include "screens/options.h"

int main ()
{
	// Tell the window to use vysnc and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window
	InitWindow(1280, 800, "Chaos");
	
	// Enter the title screen
	enum Screen curr_screen = TITLE;
	while (!WindowShouldClose()) {
		switch (curr_screen) {
			case TITLE:
				curr_screen = title_screen();
				break;
			case GAME:
				curr_screen = game_screen();
				break;
			case OPTIONS:
				curr_screen = options_screen();
				break;
			default:
				curr_screen = CLOSE_GAME;
				break;
		}

		if (curr_screen == CLOSE_GAME) {
			break;
		}
	}

	// Cleanup
	CloseWindow();
	return 0;
}