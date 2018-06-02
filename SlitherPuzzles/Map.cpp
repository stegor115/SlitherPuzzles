#include "Map.h"

Map::Map() {

}

Map::~Map() {

}

//Snake almost always starts at x = 0, y = 400
//This might be different depending on the level
//Window Info: 600x600
//Important Note: Active Rects needs to be correct, otherwise the snake has no collision detection of preceding rectangles.
//Map generation
void Map::stageOne() {
	//First rectangle
	generateRect(0, 425, 600, 175, 0);
	//Center blocking rectangle
	generateRect(250, 400, 100, 25, 1);
	generateRect(275, 375, 50, 25, 2);
	this->activeRects = 3;
	this->currentStage = 1;
}

void Map::stageTwo() {
	//Ground level rectangle
	generateRect(0, 425, 600, 175, 0);
	//Temporary Massive Blocking Rectangle
	generateRect(100, 300, 100, 125, 1);
	generateRect(400, 300, 100, 125, 2);
	this->activeRects = 3;
	this->currentStage = 2;
}

void Map::switchStage() {
	clearRects();
	switch (this->currentStage) {
	case 1:
		this->stageOneComplete = true;
		stageTwo();
		break;
	default:
		std::cout << "Something went very wrong, or the level is not yet implemented." << std::endl;
		this->currentStage = 666;
		break;
	} //end switch statement
	std::cout << "Level "<< this->currentStage << " Loaded" << std::endl;
}

void Map::clearRects() { //Throws rectangles off screen
	for (int i = 0; i < this->rectCount; ++i) {
		generateRect(-100, -100, 0, 0, i);
	} //end for
}

void Map::generateRect(int xPos, int yPos, int width, int height, int pos) {
	this->mapRects[pos].x = xPos;
	this->mapRects[pos].y = yPos;
	this->mapRects[pos].w = width;
	this->mapRects[pos].h = height;
}

void Map::generateUnused(int pos) {
	for (int i = pos; i < this->rectCount; ++i) {
		generateRect(-100, -100, 0, 0, i);
	} //end for
}

//Gets
int Map::getRectCount() {
	return this->rectCount;
}

SDL_Rect* Map::getRect(int pos) {
	return &this->mapRects[pos];
}

//Check collision
bool Map::checkOccupied(int xPos, int yPos) { //positions are the wanted positons, not the current ones
	//bool widthOccupied = false;
	//bool heightOccupied = false;
	for (int i = 0; i < this->activeRects; ++i) {
		for (int j = getRect(i)->x; j < getRect(i)->x + getRect(i)->w; j += 25) { //25 is the velocity of the snake
			for (int k = getRect(i)->y; k < getRect(i)->y + getRect(i)->h; k += 25) { //25 is the velocity of the snake
				if (xPos == j && yPos == k) {
					std::cout << "Movement restricted by map" << std::endl;
					return true;
				}
			} //end height inner for
		} //end width inner for
	} //end activeRect for
 return false;
}