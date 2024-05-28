#include <iostream>
#include "Window.h"

int main(int argc, char* argv[])
{
	Window* window = Window::get();
	window->init();
	window->loop();

	return 0;
}