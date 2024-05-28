#ifndef COLLISION_H
#define COLLISION_H

#include <iostream>
#include "Snake.h"
#include "Apple.h"
#include "score.h"

class Collision
{
	static Collision* instance;
	Collision();
public:
	static Collision* get();
	static void appleSnakeCollision(Snake *snake, Apple *apple, Score &score);
	static void snakeHeadBodyCollision(Snake* snake, Score& score);
};

#endif // !COLLISION_H
