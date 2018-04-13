#include "SDL.h"

class Snake {
public:
	Snake();
	~Snake();
	//Set/Get X and Y
	void setHeadX(int value);
	void setHeadY(int value);
	int getHeadX();
	int getHeadY();
	//Size
	void setSize(int value);
	int getSize();
	//Speed
	void setVelocity(int value);
	int getVelocity();
	SDL_Rect* getHead();
private:
	SDL_Rect snakeHead;
	int tailLength;
	int velocity = 0;
	SDL_Rect snakeTail[10];
};
