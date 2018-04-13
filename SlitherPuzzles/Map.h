#include "SDL.h"
class Map {
public:
	Map();
	~Map();
	void stageOne();
	void stageTwo();
	void clearRects();
	bool checkOccupied(int xPos, int yPos);
private:
	SDL_Rect mapRects[10]; //Increase as needed
};