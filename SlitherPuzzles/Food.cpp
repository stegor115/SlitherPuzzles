#include "Food.h"

Food::Food() {

}

Food::~Food() {

}

//Set X/Y
void Food::setX(int value) {
	this->foodRect.x = value;
}

void Food::setY(int value) {
	this->foodRect.y = value;
}

//Get X/Y
int Food::getX() {
	return this->foodRect.x;
}

int Food::getY() {
	return this->foodRect.y;
}

//Food retrieval
bool Food::gotFood(int xPos, int yPos) { //xPos and yPos are from the Snake Head
	if (xPos == this->foodRect.x && yPos == this->foodRect.y) {
		return true;
	} //end if
	return false;
}

//Size handling
void Food::setSize(int value) {
	this->foodRect.w = value;
	this->foodRect.h = value;
}

int Food::getSize() {
	return this->foodRect.w; //Same as height
}

SDL_Rect* Food::getFood() {
	return &this->foodRect;
}