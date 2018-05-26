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

//Get X/Y of Head
int Snake::getHeadX() {
	return this->snakeHead.x;
}

int Snake::getHeadY() {
	return this->snakeHead.y;
}

//Set X/Y of Tail
void Snake::setTailX(int pos, int value) {
	this->snakeTail[pos].x = value;
}

void Snake::setTailY(int pos, int value) {
	this->snakeTail[pos].y = value;
}

//Get X/Y of Tail
int Snake::getTailX(int pos) {
	return this->snakeTail[pos].x;
}

int Snake::getTailY(int pos) {
	return this->snakeTail[pos].y;
}

//Size handling
void Snake::setSize(int value) {
	this->snakeHead.w = value;
	this->snakeHead.h = value;
}

int Snake::getSize() {
	return this->snakeHead.w; //Same as height
}

//Get Rects
SDL_Rect* Snake::getHead() {
	return &this->snakeHead;
}

SDL_Rect* Snake::getTail(int pos) {
	return &this->snakeTail[pos];
}

//Set Rects
void Snake::setRect2Rect(SDL_Rect* first, SDL_Rect* second) {
	first->x = second->x;
	first->y = second->y;
	first->w = second->w;
	first->h = second->h;
}

//Get Tail Length
int Snake::getTailLength() {
	return this->tailLength;
}

//Hide Snake Tail
void Snake::hideTail() {
	for (int i = 0; i < getTailLength(); ++i) {
		setTailX(i, -100);
		setTailY(i, -100);
	} //end for
}

//Velocity
void Snake::setVelocity(int value) {
	this->velocity = value;
}

int Snake::getVelocity() {
	return this->velocity;
}

//Spawn
void Snake::spawn() { //Always spawns snake in the same position
	setHeadX(0);
	setHeadY(400);
	setSize(25);
	setVelocity(25);
}

void Snake::spawn(int xPos, int yPos) { //Spawns snake in a custom position if desired
	setHeadX(xPos);
	setHeadY(yPos);
	setSize(25);
	setVelocity(25);
}