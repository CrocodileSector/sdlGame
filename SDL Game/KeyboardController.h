#pragma once

#include "Game.h"
#include "Components.h"

class KeyboardController : public Component
{
private:
	TransformComponent* m_transform;

public:
	KeyboardController() = default;

	void init() override;

	void update() override;
};
