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

//Movement
void Snake::moveUp(int windowLimit) {
	if (this->snakeHead.y - this->velocity >= windowLimit) { //Check off screen
		moveTail();
		this->snakeHead.y = this->snakeHead.y - this->velocity;
	} //end if
}

void Snake::moveDown(int windowLimit) {
	bool tailObstruct = false;
	bool tailClimb = false;;
		if (this->snakeHead.y + this->velocity < windowLimit) { //Check off screen
				for (int i = 0; i < this->tailLength; ++i) { //Check if tail is in the way
					if (this->snakeHead.y + this->velocity == this->snakeTail[i].y && this->snakeHead.x == this->snakeTail[i].x) {
						std::cout << "Downward movement obstructed by tail." << std::endl;
						tailObstruct = true;
					} //end if
				} //end for
				if (!tailObstruct) {
					moveTail();
					this->snakeHead.y = this->snakeHead.y + this->velocity;
				} //end tail obstruction if
		} //end off-screen if
}

void Snake::moveRight(int windowLimit) {
	bool tailObstruct = false;
	bool tailClimb = false;
	if (this->snakeHead.x + this->velocity < windowLimit) { //Check off screen
			for (int i = 0; i < this->tailLength; ++i) { //Check if tail is in the way
				if (this->snakeHead.x + this->velocity == this->snakeTail[i].x) {
					if (this->snakeHead.y - this->velocity == this->snakeTail[i].y) {
						std::cout << "Rightward movement obstructed by tail." << std::endl;
						tailObstruct = true;
					} //end if
					else {
						if (this->snakeHead.x + this->velocity == this->snakeTail[i].x && this->snakeHead.y == this->snakeTail[i].y && !tailObstruct) {
							tailClimb = true;
						} //end if
					} //end else
				} //end if
			} //end for
			if (tailClimb) {
				moveTail();
				this->snakeHead.x = this->snakeHead.x + this->velocity;
				this->snakeHead.y = this->snakeHead.y - this->velocity;
				std::cout << "Climbed tail via rightward movement." << std::endl;
			} //end if
			else if (!tailObstruct) {
				moveTail();
				this->snakeHead.x = this->snakeHead.x + this->velocity;
			} //end if
	} //end off screen if
}

void Snake::moveLeft(int windowLimit) {
	bool tailObstruct = false;
	bool tailClimb = false;
	if (this->snakeHead.x - this->velocity >= windowLimit) { //Check off screen
			for (int i = 0; i < this->tailLength; ++i) { //Check if tail is in the way
				if (this->snakeHead.x - this->velocity == this->snakeTail[i].x) {
					if (this->snakeHead.y - this->velocity == this->snakeTail[i].y) {
						std::cout << "Leftward movement obstructed by tail." << std::endl;
						tailObstruct = true;
					} //end if
					else {
						if (this->snakeHead.x - this->velocity == this->snakeTail[i].x && this->snakeHead.y == this->snakeTail[i].y && !tailObstruct) {
							tailClimb = true;
						} //end if
					} //end else
				} //end if
			} //end for
			if (tailClimb) {
				moveTail();
				this->snakeHead.x = this->snakeHead.x - this->velocity;
				this->snakeHead.y = this->snakeHead.y - this->velocity;
				std::cout << "Climbed tail via leftward movement." << std::endl;
			} //end if
			else if (!tailObstruct) {
				moveTail();
				this->snakeHead.x = this->snakeHead.x - this->velocity;
			} //end if
	} //end off screen if
}

//Tail handling
void Snake::moveTail() {
	for (int i = 0; i < this->tailLength; ++i) {
		this->setRect2Rect(this->getTail(i), this->getTail(i + 1));
	} //end for
	if (this->getTailLength() != 0) {
		this->setRect2Rect(this->getTail(this->getTailLength() - 1), this->getHead());
	} //end if
}

//Spawn
void Snake::spawn() { //Always spawns snake in the same position
	this->snakeHead.x = 0;
	this->snakeHead.y = 400;
	this->snakeHead.w = 25;
	this->snakeHead.h = 25;
	this->velocity = 25;
	hideTail();
}

void Snake::spawn(int xPos, int yPos) { //Spawns snake in a custom position if desire
	this->snakeHead.x = xPos;
	this->snakeHead.y = yPos;
	this->snakeHead.w = 25;
	this->snakeHead.h = 25;
	this->velocity = 25;
	hideTail(); //This might look weird if not spawned on the edge of the screen, might need a solution?
}