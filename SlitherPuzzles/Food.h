#include "SDL.h"
//#include "Snake.h"

class Food {
public:
	Food();
	~Food();
	//Set/Get X and Y
	void setX(int value);
	void setY(int value);
	int getX();
	int getY();
	bool gotFood(int xPos, int yPos); //xPos and yPos are from the Snake
	//Size
	void setSize(int value);
	int getSize();
	SDL_Rect* getFood();
private:
	SDL_Rect foodRect;
};
