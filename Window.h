#ifndef WINDOW_H
#define WINDOW_H

#define CELLSIZE 20
#define CELLROWS 40
#define CELLCOLUMNS 30
#define WINDOW_WIDTH CELLROWS * CELLSIZE
#define WINDOW_HEIGHT CELLCOLUMNS * CELLSIZE
#define FPS 12

#include <SDL2/SDL.h>
#include <iostream>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "Snake.h"
#include "Collision.h"
#include "Score.h"

class Window
{
	static Window* instance;

	bool running;

	SDL_Window* window;
	SDL_Renderer* renderer ;
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