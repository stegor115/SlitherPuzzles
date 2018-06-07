#include <iostream>
#include "SDL.h"

class Snake {
public:
	Snake();
	~Snake();
	//Set/Get X and Y
	//Some of these functions might be redundant, keep until known for sure they are.
	void setHeadX(int value);
	void setHeadY(int value);
	void setTailX(int pos, int value);
	void setTailY(int pos, int value);
	int getHeadX();
	int getHeadY();
	int getTailX(int pos);
	int getTailY(int pos);
	int getTailLength();
	void hideTail();
	//Size
	void setSize(int value);
	int getSize();
	//Speed
	void setVelocity(int value);
	int getVelocity();
	//Movement
	//Clean up the below so less function calls happen
	void moveUp(int windowLimit);
	void moveDown(int windowLimit);
	void moveLeft(int windowLimit);
	void moveRight(int windowLimit);
	//Handle Tail
	void moveTail();
	//Spawn
	void spawn(); //Default spawn location
	void spawn(int xPos, int yPos); //Customizable spawn location if desired
	//Get Rects
	SDL_Rect* getHead();
	SDL_Rect* getTail(int pos); //pos = part of tail
	//Set Rects
	void setRect2Rect(SDL_Rect* first, SDL_Rect* second);
private:
	SDL_Rect snakeHead;
	int tailLength = 10;
	int velocity = 0;
	SDL_Rect snakeTail[10];
};
