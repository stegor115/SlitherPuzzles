#include "SDL.h"

class Food {
public:
	Food();
	~Food();
	//Set/Get X and Y
	void setX(int value);
	void setY(int value);
	int getX();
	int getY();
	//Size
	void setSize(int value);
	int getSize();
	SDL_Rect* getFood();
private:
	SDL_Rect foodRect;
};
