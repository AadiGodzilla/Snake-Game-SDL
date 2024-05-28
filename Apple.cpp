#include "Apple.h"

Apple::Apple()
{

}

Apple::Apple(int x, int y, int cellsize)
{
	this->x = x;
	this->y = y;
	this->cellsize = cellsize;

	randomPlacement();
	
}

void Apple::randomPlacement()
{
	apple.x = (rand() % x) * cellsize;
	apple.y = (rand() % y) * cellsize;
	apple.w = cellsize;
	apple.h = cellsize;
}

void Apple::render(SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer, &apple);
}

SDL_Rect *Apple::getRect()
{
	return &this->apple;
}