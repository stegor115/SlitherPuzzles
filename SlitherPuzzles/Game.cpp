#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Game.h"
#include "Snake.h"
#include "Food.h"
#include "Map.h"

Snake *playerSnake = new Snake();
Food *foodGoal = new Food();
Map *myMap = new Map();

Game::Game() {
}

Game::~Game() {
}
//TO-DO-------------------------------------------------------------------------------
// Add gravity
// MAYBE: Add key to open a door to reach the food?
//------------------------------------------------------------------------------------

//KNOWN BUGS-------------------------------------------------------------------------------
// Fix bug that does not allow snake to travel right or left when immediate left/right is open (no climb), this bug can trap the snake if not fixed.
// It's possible to climb on the snake's tail and go through the map if a part of the map is above the snake.
//------------------------------------------------------------------------------------
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
	playerSnake->spawn();
	//Food
	foodGoal->setX(575);
	foodGoal->setY(400);
	foodGoal->setSize(25);
	//Stage
	myMap->stageOne();
	this->startTime = SDL_GetTicks();
}

void Game::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);
	bool tailObstruct = false;
	bool tailClimb = false;
	switch (event.type) {
	case SDL_KEYDOWN: //Key pressed
		switch (event.key.keysym.sym) {
		case SDLK_w: //Debug movement to go upward
		case SDLK_UP:
			if (this->devMode) { //Only possible if Dev mode is on
				playerSnake->moveUp(0); //Top of screen is x = 0.
			} //end if
			break;
		case SDLK_s:
		case SDLK_DOWN:
			if (!myMap->checkOccupied(playerSnake->getHeadX(), playerSnake->getHeadY() + playerSnake->getVelocity())) { //Check if map is in the way, also had issues moving this into moveDown()
				playerSnake->moveDown(this->windowHeight);
			} //end map collision if
			break;
		case SDLK_a:
		case SDLK_LEFT:
			if (!myMap->checkOccupied(playerSnake->getHeadX() - playerSnake->getVelocity(), playerSnake->getHeadY())) { //Check if map is in the way
				playerSnake->moveLeft(0); //Left border of screen is y = 0
			} //end map collision if
			break;
		case SDLK_d:
		case SDLK_RIGHT:
			if (!myMap->checkOccupied(playerSnake->getHeadX() + playerSnake->getVelocity(), playerSnake->getHeadY())) { //Check if map is in the way
				playerSnake->moveRight(this->windowWidth);
			} //end map collision if
			break;
		case SDLK_r:
			//Restart Level
			playerSnake->spawn();
			playerSnake->hideTail();
			break;
		case SDLK_BACKQUOTE:
			toggleDev();
			break;
		case SDLK_RETURN: //Enter Key
			if (this->devMode) {
				issueCommand();
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

	//Special Events-----------------------------------------
	if (foodGoal->gotFood(playerSnake->getHeadX(), playerSnake->getHeadY())) { //Getting food
		myMap->switchStage();
		playerSnake->spawn();
	} //end if
}

void Game::eventOccured() { //Meant to handle tail information of the snake
	for (int i = 0; i < playerSnake->getTailLength(); ++i) {
		playerSnake->setRect2Rect(playerSnake->getTail(i), playerSnake->getTail(i + 1));
	}
	if (playerSnake->getTailLength() != 0) {
		playerSnake->setRect2Rect(playerSnake->getTail(playerSnake->getTailLength() - 1), playerSnake->getHead());
	}
}

void Game::update() { //Each frame
	//Clear Screen
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); //Sets color to black
	SDL_RenderClear(renderer); //Clears screen
	//Draw Stage
	for (int i = 0; i < myMap->getRectCount(); ++i) {
		SDL_SetRenderDrawColor(renderer, 0, 0, 200, 0);
		SDL_RenderFillRect(renderer, myMap->getRect(i)); //Hardcoded zero for testing purposes
	}
	//Draw food/goal rectangle
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0); //Sets color to green
	SDL_RenderFillRect(renderer, foodGoal->getFood()); //Sets up rectangle to render
	//Draw snake rectangle
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0); //Sets color to green
	SDL_RenderFillRect(renderer, playerSnake->getHead()); //Sets up rectangle to render
	//Draw snake tail
	for (int i = 0; i < playerSnake->getTailLength(); ++i) {
		SDL_SetRenderDrawColor(renderer, 0, 100, 0, 0); //Sets color to green
		SDL_RenderFillRect(renderer, playerSnake->getTail(i)); //Sets up rectangle to render
	} //end for
	SDL_RenderPresent(renderer); //Renders
}

bool Game::running(){
	return this->isRunning;
}

void Game::toggleDev() {
	if (this->devMode == false) {
		this->devMode = true;
		std::cout << "Developer Mode toggled ON" << std::endl;
	} //end if
	else {
		this->devMode = false;
		std::cout << "Developer Mode toggled OFF" << std::endl;
	} //end else
}

void Game::issueCommand() {
	std::string command;
	int num;
	std::cout << "Enter Command:" << std::endl;
	std::cin >> command;
	//Change the following to a switch case at some point
	if (command == "map") { //Manual map switching
		std::cin >> num;
		switch (num) {
		case 1:
			myMap->clearRects();
			myMap->stageOne();
			std::cout << "Stage " << num << " Loaded" << std::endl;
			break;
		case 2:
			myMap->clearRects();
			myMap->stageTwo();
			std::cout << "Stage " << num << " Loaded" << std::endl;
			break;
		case 3:
			myMap->clearRects();
			myMap->stageThree();
			std::cout << "Stage " << num << " Loaded" << std::endl;
			break;
		default:
			std::cout << "Stage " << num << " does not exist." << std::endl;
			break;
		}//end map switch statement
	} //end map if statement
	else if (command == "help") { //Command List
		std::cout << "help - Provides list of all available commands." << std::endl;
		std::cout << "map <number> - Loads map based on the number." << std::endl;
	} //end help if
	else {
		std::cout << "Command does not exist. Use 'help' for a list." << std::endl;
	}
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

Uint32 Game::timer() {
	return SDL_GetTicks() - this->startTime;
}