#ifndef SNAKE_H
#define SNAKE_H

#include <SDL2/SDL.h>
#include <deque>

class Snake 
{
	int initx, inity;
	int cellsize, bodySize;
	SDL_Rect head;
	SDL_Rect part;
	std::deque<SDL_Rect> body;
public:
	Snake();
	Snake(int x, int y, int cellsize);
	enum Direction {UP, DOWN, LEFT, RIGHT, NOMOVE};
	Direction direction;
	bool death;
	SDL_Rect* getHead();
	std::deque<SDL_Rect> getBody();
	void movement();
	void addBody();
	void boundary(int bstartx, int bstarty, int bendx, int bendy);
	void render(SDL_Renderer *renderer);
	void reset();
};

#endif // !SNAKE_H
