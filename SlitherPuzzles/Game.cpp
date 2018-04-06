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
		isRunning = true;
	}//end init if
} //end init

void Game::startGame() {
	playerSnake->setHeadX(400);
	playerSnake->setHeadY(400);
	playerSnake->setSize(25);
}

void Game::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
	}
}

void Game::update() { //Each frame
	//Clear Screen
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); //Sets color to black
	SDL_RenderClear(renderer); //Clears screen
	//Draw snake rectangle
	SDL_SetRenderDrawColor(renderer, 0, 100, 0, 0); //Sets color to green
	SDL_RenderFillRect(renderer, playerSnake->getHead()); //Sets up rectangle to render
	SDL_RenderPresent(renderer); //Renders
}

bool Game::running(){
	return this->isRunning;
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}