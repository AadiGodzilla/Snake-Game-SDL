#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <iostream>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "Snake.h"
#include "Apple.h"
#include "Collision.h"
#include "Score.h"

class Window
{
	static Window* instance;

	int CELL_SIZE;
	int CELL_ROWS, CELL_COLUMN;
	int SCREEN_HEIGHT, SCREEN_WIDTH;

	bool running;

	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event event;

	Snake snake;
	Apple apple;
	Score score;

	Window();
	~Window();

public:
	static Window* get();
	void init();
	void loop();
};

#endif