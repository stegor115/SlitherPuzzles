#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string> //Used for command input
#include <SDL.h>

class Game {
public:
	Game();
	~Game();
	void init(const char* title, int width, int height); //Game window
	void startGame();
	void handleEvents(); //Cleaning up
	void eventOccured(); //Incoming redundancy
	void update();
	bool running();
	void toggleDev();
	void issueCommand();
	void clean();
	Uint32 timer();
private:
	bool isRunning = false;
	bool devMode = false;
	SDL_Window *window;
	SDL_Renderer *renderer;
	int windowWidth = 0;
	int windowHeight = 0;
	//FPS
	Uint32 startTime;
};