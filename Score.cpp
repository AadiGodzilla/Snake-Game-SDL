#include "Score.h"

Score::Score()
{

}

Score::Score(SDL_Renderer *renderer, const char* fontPath, int fontsize)
{
	fontPath = fontPath;
	fontsize = fontsize;
	score = 0;

	scoreRect.x = 10;
	scoreRect.y = 10;
	scoreRect.w = 120;
	scoreRect.h = 30;

	font = TTF_OpenFont(fontPath, fontsize);
}

void Score::addScore()
{
	score++;
}

void Score::resetScore()
{
	score = 0;
}

void Score::render(SDL_Renderer* renderer, const SDL_Color& color)
{
	std::string scorestring = "Score: ";
	scorestring += std::to_string(score);

	SDL_Surface* scoreSurface = TTF_RenderText_Solid(font, scorestring.c_str(), color);
	SDL_Texture* scoreTexture = SDL_CreateTextureFromSurface(renderer, scoreSurface);

	SDL_FreeSurface(scoreSurface);

	SDL_RenderCopy(renderer, scoreTexture, NULL, &scoreRect);
}