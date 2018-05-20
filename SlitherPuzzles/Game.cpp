#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Game.h"
#include "Snake.h"
#include "Food.h"

Snake *playerSnake = new Snake();
Food *foodGoal = new Food();

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
	//Snake
	playerSnake->setHeadX(0);
	playerSnake->setHeadY(400);
	playerSnake->setSize(25);
	playerSnake->setVelocity(25);
	//Food
	foodGoal->setX(575);
	foodGoal->setY(400);
	foodGoal->setSize(25);
	this->startTime = SDL_GetTicks();
}

void Game::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_KEYDOWN: //Key pressed
		switch (event.key.keysym.sym) {
		case SDLK_w: //This eventually needs to be removed, to go up, the snake needs to go backward onto itself
		case SDLK_UP:
			if (playerSnake->getHeadY() - playerSnake->getVelocity() >= 0) { //Check off screen
				playerSnake->setHeadY(playerSnake->getHeadY() - playerSnake->getVelocity());
			} //end if
			break;
		case SDLK_s:
		case SDLK_DOWN:
			if (playerSnake->getHeadY() + playerSnake->getVelocity() < this->windowHeight) { //Check off screen
				playerSnake->setHeadY(playerSnake->getHeadY() + playerSnake->getVelocity());
			} //end if
			break;
		case SDLK_a:
		case SDLK_LEFT:
			if (playerSnake->getHeadX() - playerSnake->getVelocity() >= 0) { //Check off screen
				playerSnake->setHeadX(playerSnake->getHeadX() - playerSnake->getVelocity());
			} //end if
			break;
		case SDLK_d:
		case SDLK_RIGHT:
			if (playerSnake->getHeadX() + playerSnake->getVelocity() < this->windowWidth) { //Check off screen
				playerSnake->setHeadX(playerSnake->getHeadX() + playerSnake->getVelocity());
			} //end if
			break;
		} //end inner switch statement
		break; //Stops potential run on to SDL_QUIT
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	} //end outer switch statement
}

void Game::update() { //Each frame
	//Get Tail information
	for (int i = 0; i < playerSnake->getTailLength(); ++i) {
		playerSnake->setRect2Rect(playerSnake->getTail(i), playerSnake->getTail(i + 1));
	}
	if (playerSnake->getTailLength() != 0) {
		playerSnake->setRect2Rect(playerSnake->getTail(playerSnake->getTailLength() - 1), playerSnake->getHead());
	}
	//Clear Screen
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); //Sets color to black
	SDL_RenderClear(renderer); //Clears screen
	//Draw food/goal rectangle
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0); //Sets color to green
	SDL_RenderFillRect(renderer, foodGoal->getFood()); //Sets up rectangle to render
	//SDL_RenderPresent(renderer); //Renders
	//Draw snake rectangle
	SDL_SetRenderDrawColor(renderer, 0, 100, 0, 0); //Sets color to green
	SDL_RenderFillRect(renderer, playerSnake->getHead()); //Sets up rectangle to render
	//Draw snake tail
	for (int i = 0; i < playerSnake->getTailLength(); ++i) {
		//std::cout << "tailX = " << this->snakeTail[i].x << " tailY = " << this->snakeTail[i].y << std::endl;
		SDL_SetRenderDrawColor(renderer, 0, 100, 0, 0); //Sets color to green
		SDL_RenderFillRect(renderer, playerSnake->getTail(i)); //Sets up rectangle to render
		//Debug lines
		std::cout << "Tail Piece = " << i << " TailX = " << playerSnake->getTailX(i) << " TailY = " << playerSnake->getTailY(i) << std::endl;
	} //end for
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

Uint32 Game::timer() {
	return SDL_GetTicks() - this->startTime;
}