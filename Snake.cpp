#include "Snake.h"
#include <iostream>

Snake::Snake()
{

}

Snake::Snake(int x, int y, int cellsize)
{
	this->cellsize = cellsize;
	initx = x;
	inity = y;

	bodySize = 4;
	direction = DOWN;
	
	head = { initx, inity, cellsize, cellsize };
	part = { head.x, head.y, cellsize, cellsize }; 
	
	for (int i = 0; i < bodySize; i++)
	{
		part.x += cellsize;
		body.push_front(part);
	}

	reset();
}

SDL_Rect* Snake::getHead()
{
	return &this->head;
}

std::deque<SDL_Rect> Snake::getBody()
{
	return this->body;
}

void Snake::movement()
{
	switch (direction)
	{
	case UP: head.y -= cellsize, part.y = head.y - cellsize; break;
	case DOWN: head.y += cellsize;part.y = head.y + cellsize; break;
	case LEFT: head.x -= cellsize;part.x = head.x - cellsize; break;
	case RIGHT: head.x += cellsize;part.x = head.x + cellsize; break;
	}

	body.push_front(head);

	if (body.size() > bodySize)
		body.pop_back();
}

void Snake::boundary(int bstartx, int bstarty, int bendx, int bendy) 
{
	if (head.x < -bstartx)
		head.x = bendx;
	else if (head.x > bendx)
		head.x = bstartx - cellsize;

	else if (head.y < -bstarty)
		head.y = bendy;
	else if (head.y > bendy)
		head.y = bstarty - cellsize;
}

void Snake::render(SDL_Renderer *renderer)
{
	for (SDL_Rect part : body)
	{
		SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
		SDL_RenderFillRect(renderer, &part);
	}

	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	SDL_RenderFillRect(renderer, &head);
}

void Snake::addBody()
{
	bodySize++;
}

void Snake::reset()
{
	bodySize = 4;
	while (body.size() != bodySize)
	{
		body.pop_back();
	}
}