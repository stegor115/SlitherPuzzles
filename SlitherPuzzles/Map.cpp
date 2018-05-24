#include "Map.h"

Map::Map() {

}

Map::~Map() {

}

//Snake always starts at x = 0, y = 400
//Window Info: 600x600
//Map generation
void Map::stageOne() {
	//First rectangle
	generateRect(0, 425, 600, 175, 0);
	generateRect(250, 400, 100, 25, 1);
}

void Map::stageTwo() {

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
	for (int i = 0; i < this->rectCount; ++i) {

	}
	return false;
}