#include "SDL.h"

class Snake {
public:
	Snake();
	~Snake();

private:
	SDL_Rect snakeHead;
	int tailLength;
	SDL_Rect snakeTail[10];
};
