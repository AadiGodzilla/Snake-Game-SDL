#ifndef SCORE_H
#define SCORE_H

#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include <SDL2/SDL_ttf.h>

class Score
{
	int score;
	const char* fontPath = "";
	int fontsize = 0;

	TTF_Font *font;
	SDL_Rect scoreRect;

public:
	Score();
	Score(SDL_Renderer* renderer, const char* fontPath, int fontsize);
	void addScore();
	void resetScore();
	void render(SDL_Renderer* renderer, const SDL_Color &color);
};

#endif
