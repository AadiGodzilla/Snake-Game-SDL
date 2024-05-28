#include "Collision.h"
#include <SDL2/SDL_ttf.h>

Collision* Collision::instance = nullptr;

Collision::Collision()
{

}

Collision* Collision::get()
{
	if (instance == nullptr)
	{
		instance = new Collision();
	}

	return instance;
}

void Collision::appleSnakeCollision(Snake *snake, Apple *apple, Score &score)
{
	const SDL_Rect* snakeRect = snake->getHead();
	const SDL_Rect* appleRect = apple->getRect();
	bool collision = SDL_HasIntersection(snakeRect, appleRect);

	if (collision)
	{
		apple->randomPlacement();
		snake->addBody();
		score.addScore();
	}
}

void Collision::snakeHeadBodyCollision(Snake* snake, Score& score)
{
	for (size_t i = 1; i < snake->getBody().size(); i++)
	{
		if (
			snake->getHead()->x == snake->getBody()[i].x && 
			snake->getBody()[i].y == snake->getHead()->y
			)
		{
			score.resetScore();
			snake->reset();
		}
	}
}