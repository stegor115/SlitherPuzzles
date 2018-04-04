#include "Game.h"
#include "Snake.h"

Snake *playerSnake = new Snake();

Game::Game() {
}

Game::~Game() {
}

void Game::init(const char* title, int width, int height) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
		renderer = SDL_CreateRenderer(window, -1, 0);
		this->windowWidth = width;
		this->windowHeight = height;
		if (renderer) {
			startGame();
		}//end renderer if
		this->isRunning = true;
	}//end init if
} //end init

void Game::startGame() {

}

void Game::handleEvents() {

}

void Game::update() { //Each frame

}

bool Game::running(){
	return this->isRunning;
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}