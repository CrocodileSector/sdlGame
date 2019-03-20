#pragma once

#include "Game.h"
#include "Components.h"

class KeyboardController : public Component
{
private:
	TransformComponent* m_transform;
	  
public:

	void init() override
	{
		m_transform = &(m_entity->getComponent<TransformComponent>());
	}

	void update() override
	{
		SDL_Event curentrEvent = Game::GetEvent();
		if (curentrEvent.type == SDL_KEYDOWN)
		{
			switch (curentrEvent.key.keysym.sym)
			{
			case SDLK_w:
				m_transform->SetVelocityY(-1.0f);
				break;
			case SDLK_a:
				m_transform->SetVelocityX(-1.0f);
				break;
			case SDLK_s:
				m_transform->SetVelocityY(1.0f);
				break;
			case SDLK_d:
				m_transform->SetVelocityX(1.0f);
				break;
			case SDLK_SPACE:
			case SDLK_ESCAPE:
			default:
				break;
			}
		}

		if (curentrEvent.type == SDL_KEYUP)
		{
			switch (curentrEvent.key.keysym.sym)
			{
			case SDLK_w:
				m_transform->SetVelocityY(0.0f);
				break;
			case SDLK_a:
				m_transform->SetVelocityX(0.0f);
				break;
			case SDLK_s:
				m_transform->SetVelocityY(0.0f);
				break;
			case SDLK_d:
				m_transform->SetVelocityX(0.0f);
				break;
			case SDLK_SPACE:
			case SDLK_ESCAPE:
			default:
				break;
			}
		}
	}
};
