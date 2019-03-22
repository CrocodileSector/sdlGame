#include "ColliderComponent.h"

ColliderComponent::ColliderComponent(std::string tag) : m_tag(tag) { }

TransformComponent* ColliderComponent::GetTransform() const
{
	if (m_transform)
		return m_transform;
}

void ColliderComponent::init()
{
	m_transform = &(m_entity->getComponent<TransformComponent>());

	if (m_tag.compare("player") == 0)
		Game::RegisterCollider(this, true);
	else
		Game::RegisterCollider(this, false);
}

void ColliderComponent::update()
{
	m_collider.x = static_cast<int>(m_transform->GetX());
	m_collider.y = static_cast<int>(m_transform->GetY());

	m_collider.w = m_transform->GetWidth() * m_transform->GetScale();
	m_collider.h = m_transform->GetHeight() * m_transform->GetScale();
}