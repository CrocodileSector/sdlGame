#include "Game.h"

#include "Map.h"
#include "Components.h"
#include "TextureManager.h"

const int WindowHeight = 800;
const int WindowWidth = 640;
bool Fullscreen = false;

unsigned long long Game::loopCounter = 0;
bool Game::rendererActive = false;
SDL_Event Game::m_event;
std::vector<ColliderComponent*> Game::m_colliders;

SDL_Renderer* Game::m_renderer = nullptr;
Map* stage = nullptr;

EntityManager manager;
auto& player(manager.addEntity());

Game::Game()
{
	init("2D SDL Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WindowHeight, WindowWidth, Fullscreen);
}

Game::~Game()
{
	quit();
}

void Game::init(const char* i_title, int i_x, int i_y, int i_w, int i_h, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		m_window = SDL_CreateWindow(i_title, i_x, i_y, i_w, i_h, SDL_WINDOW_SHOWN + ( fullscreen ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_RESIZABLE ));

		if (!m_window)
		{
			std::stringstream err;
			err << "Failed to create window...  SDL Error: " << SDL_GetError() << std::endl;
			throw std::runtime_error(err.str());
		}

		m_renderer = SDL_CreateRenderer(m_window, -1, 0);

		if (!m_renderer)
		{
			std::stringstream err;
			err << "Failed to create renderer...  SDL Error: " << SDL_GetError() << std::endl;
			throw std::runtime_error(err.str());
		}

		SDL_SetRenderDrawColor(m_renderer, 255, 0, 128, 255);

		SDL_RenderClear(m_renderer);

		Game::rendererActive = true;

		stage = new Map(3, 32);
		stage->LoadMap("Assets/map3.map", 20, 25);

		player.addComponent<TransformComponent>(10.0f, 10.0f, 32, 32, 2);
		player.addComponent<SpriteComponent>("Assets/wolfie.png");
		player.addComponent<KeyboardController>();
		player.addComponent<ColliderComponent>("player");

		m_state = Created;

		std::cout << "Game succesfully created... Enjoy!" << std::endl;

		run(); //call run internally once to set the instance to Running state
	}
	else
	{
		m_state = Broken;
		std::stringstream err;
		err << "Failed to init something...  SDL Error: " << SDL_GetError() << std::endl;
		throw std::runtime_error(err.str());
	}
}

void Game::run()
{
	
	switch (m_state)
	{
	case Created:
		m_state = Running;
		break;
	case Running:
	{
		//handle user input
		//update all objects on the screen
		//render changes to the display

		handleEvents();
		update();
		render();

		break;
	}
	case ShuttingDown:
		//TODO: do something
		break;
	case Broken:
		//TODO: do something
		break;
	default:
		m_state = Broken;
		break;
	}
}

void Game::handleEvents()
{
	SDL_PollEvent(&m_event);

	switch (m_event.type)
	{
	case SDL_QUIT:
		quit();
		break;
	default:
		break;
	}
}

void Game::update()
{
	++Game::loopCounter;

	manager.refresh();
	manager.update();

	Collision::CheckForCollisions(m_colliders);
}

void Game::render()
{
	SDL_RenderClear(m_renderer);

	manager.draw();

	SDL_RenderPresent(m_renderer);
}

void Game::quit()
{
	m_state = ShuttingDown;

	if (m_window)
	{
		SDL_DestroyWindow(m_window);
		m_window = nullptr;
	}
		
	if (m_renderer)
	{
		SDL_DestroyRenderer(m_renderer);
		m_renderer = nullptr;
		Game::rendererActive = false;
	}

	SDL_Quit();
}