#ifndef APPLE_H
#define APPLE_H

#include <cstdlib>
#include <SDL2/SDL.h>
#include <iostream>

class Apple
{
	int x, y, cellsize;
	SDL_Rect apple;

public:
	Apple();
	Apple(int x, int y, int cellsize);
	void randomPlacement();
	void render(SDL_Renderer* renderer);
	SDL_Rect *getRect();
};

#endif // !APPLE_H
