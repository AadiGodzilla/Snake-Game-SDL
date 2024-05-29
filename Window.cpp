#include "Window.h"

Window* Window::instance = nullptr;

Window::Window()
{
	this->running = true;
}

Window* Window::get()
{
	if (instance == nullptr)
	{
		instance = new Window();
	}

	return instance;
}

Window::~Window()
{
	TTF_Quit();
	IMG_Quit();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Window::init()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
	TTF_Init();

	window = SDL_CreateWindow(
		"Snake Game", 
		SDL_WINDOWPOS_CENTERED, 
		SDL_WINDOWPOS_CENTERED, 
		WINDOW_WIDTH, 
		WINDOW_HEIGHT, 
		NULL
	);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_Surface* icon = IMG_Load("snake.png");
	SDL_SetWindowIcon(window, icon);
	SDL_FreeSurface(icon);

	snake = Snake(10 * CELLSIZE, 10 * CELLSIZE, CELLSIZE);
	apple = Apple(CELLROWS, CELLCOLUMNS, CELLSIZE);

	score = Score(renderer, "Arial.ttf", 20);
}

void Window::loop()
{
	while (get()->running)
	{
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT)
		{
			get()->running = false;
		}
		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_w && snake.direction != snake.DOWN) snake.direction = snake.UP;
			else if (event.key.keysym.sym == SDLK_s && snake.direction != snake.UP) snake.direction = snake.DOWN;
			else if (event.key.keysym.sym == SDLK_a && snake.direction != snake.RIGHT) snake.direction = snake.LEFT;
			else if (event.key.keysym.sym == SDLK_d && snake.direction != snake.LEFT) snake.direction = snake.RIGHT;
		}
		
		snake.boundary(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
		snake.movement();

		Collision::appleSnakeCollision(&snake, &apple, score);
		Collision::snakeHeadBodyCollision(&snake, score);

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		snake.render(renderer);
		apple.render(renderer);
		score.render(renderer, {255,255,255,255});

		SDL_RenderPresent(renderer);
		SDL_Delay(1000 / FPS);
	}
}


