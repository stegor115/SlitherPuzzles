#include "SDL.h"

class Snake {
public:
	Snake();
	~Snake();
	//Set/Get X and Y
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
