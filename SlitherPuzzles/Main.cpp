#include "Game.h"
#undef main

Game *game = nullptr;

int main() {
	srand(time(NULL));
	int WINDOW_WIDTH = 600;
	int WINDOW_HEIGHT = 600;
	game = new Game();
	game->init("Slither Puzzles", WINDOW_WIDTH, WINDOW_HEIGHT);

	while (game->running()) {
		game->handleEvents();
		game->update();
	}//end while
	game->clean();
	return 0;
}