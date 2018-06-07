#include <iostream>
#include "SDL.h"
class Map {
public:
	Map();
	~Map();
	//Stages
	void stageOne();
	void stageTwo();
	void stageThree();
	//Other map generation info
	void switchStage();
	void clearRects(); //Throws rects off screen to be rearranged
	void generateRect(int xPos, int yPos, int width, int height, int pos);
	void generateUnused(int num); //num is the first rect in the array to not be used, will throw rest of rects off screen.
	//Gets
	int getRectCount();
	SDL_Rect* getRect(int pos);
	//Check collision
	bool checkOccupied(int xPos, int yPos); //Use: Input wanted path to travel
private:
	//Current stage
	int currentStage = 0; 
	//Level complete booleans
	bool stageOneComplete = false;
	bool stageTwoComplete = false;
	//Rectangle info
	int rectCount = 20;
	int activeRects = 0;
	bool hasBarrier = false;
	SDL_Rect mapRects[20]; //Increase as needed
};