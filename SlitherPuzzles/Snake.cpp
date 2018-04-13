#include "Snake.h"

Snake::Snake() {
}

Snake::~Snake() {
}

//Set X/Y
void Snake::setHeadX(int value) {
	this->snakeHead.x = value;
}

void Snake::setHeadY(int value) {
	this->snakeHead.y = value;
}

//Get X/Y
int Snake::getHeadX() {
	return this->snakeHead.x;
}

int Snake::getHeadY() {
	return this->snakeHead.y;
}

//Size handling
void Snake::setSize(int value) {
	this->snakeHead.w = value;
	this->snakeHead.h = value;
}

int Snake::getSize() {
	return this->snakeHead.w; //Same as height
}

SDL_Rect* Snake::getHead() {
	return &this->snakeHead;
}

//Velocity
void Snake::setVelocity(int value) {
	this->velocity = value;
}

int Snake::getVelocity() {
	return this->velocity;
}