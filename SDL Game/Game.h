#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <sstream>
#include <vector>

class Game
{
public:
	Game();
	~Game();

	void run();

	bool isCreated() const { return m_state == Created ? true : false; }
	bool isRunning() const { return m_state == Running ? true : false; }
	bool isShuttingDown() const { return m_state == ShuttingDown ? true : false; }
	bool isBroken() const { return m_state == Broken ? true : false; }

	static bool hasRenderer() { return rendererActive; }
	static SDL_Renderer* GetRenderer() { return m_renderer; }

protected:
	void init(const char* i_title, int i_x, int i_y, int i_w, int i_h, bool fullscreen);
	void handleEvents();
	void update();
	void render();
	void quit();

private:

	enum eGameState
	{
		Created = 0,
		Running,
		ShuttingDown,
		Broken
	};

	eGameState m_state;
	SDL_Window* m_window;
	static bool rendererActive;
	static SDL_Renderer* m_renderer;

	static unsigned long long loopCounter;
};