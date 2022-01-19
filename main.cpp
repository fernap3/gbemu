#include <iostream>

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

int main(int argc, char* args[])
{
	std::cout << "Hello world!" << std::endl;

	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		return -1;
	}

	window = SDL_CreateWindow("gbemu", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		return -1;
	}

	screenSurface = SDL_GetWindowSurface(window);

	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 255, 0, 255));
	SDL_UpdateWindowSurface(window);
	SDL_Delay(2000);

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}


// g++ main.cpp -Wall -std=c++14  -IC:\mingw_dev_lib\include -LC:\mingw_dev_lib\lib -lSDL2main -lSDL2 -o main.exe


