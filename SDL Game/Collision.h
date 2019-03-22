#pragma once
#include "ColliderComponent.h"

struct Collision
{
	static bool AABB(const SDL_Rect& rectA, const SDL_Rect& rectB)
	{
		if (rectB.x + rectB.w >= rectA.x && rectA.x + rectA.w >= rectB.x && rectB.y + rectB.h >= rectA.y && rectA.y + rectA.h >= rectB.y)
			return true;
		else
			return false;
	}

	static bool AABB(const ColliderComponent& colA, const ColliderComponent& colB)
	{
		if (AABB(colA.GetCollider(), colB.GetCollider()))
			return true;
		else
			return false;
	}

	static void CheckForCollisions(const std::vector<ColliderComponent*>& colliders)
	{
		ColliderComponent* playerCol = (*colliders.begin());
		for (short i = 1; i < colliders.size(); ++i)
		{
			if (AABB(*playerCol, *colliders[i]))
			{
				if(colliders[i]->GetTag().compare("waterTile") == 0)
					//playerCol->GetTransform()->GetVelocity().SetXY(-1.0f, -1.0f);

				std::cout << "Collision detected between colliders: (1) " << playerCol->GetTag() << " and (2) " << colliders[i]->GetTag() << std::endl;
			}
		}
	}
};