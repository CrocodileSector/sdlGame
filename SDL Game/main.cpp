#include <iostream>
#include <SDL.h>
#include "Game.h"

Game* game = nullptr;

int main(int argc, char* argv[])
{
	try
	{
		const int fps = 60;
		const int frameDelay = 1000 / fps;

		Uint32 frameStart;
		int frameTime;

		game = new Game;

		while (game->isRunning())
		{
			frameStart = SDL_GetTicks();

			game->run();

			if (game->isShuttingDown())
				break;

			frameTime = SDL_GetTicks() - frameStart;

			if (frameDelay > frameTime)
				SDL_Delay(frameDelay - frameTime);
		}
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;;
	}

	std::cout << "Game is shutting down... Thank you for playing!" << std::endl;

	delete game;

	return 0;
}