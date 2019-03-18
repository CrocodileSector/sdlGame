#pragma once

#include <iostream>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>
#include <vector>

class Component;
class Entity;

const std::size_t MaxComponents = 32;
typedef std::size_t ComponentID;
typedef std::bitset<MaxComponents> ComponentBitset;
typedef std::array<Component*, MaxComponents> ComponentArray;

inline ComponentID getComponentTypeID()
{
	static ComponentID lastID = 0;
	return ++lastID;
}

template<typename T> inline ComponentID getComponentTypeID()
{
	static_assert(std::is_base_of<Component, T>::value, "");
	static ComponentID typeID = getComponentTypeID();
	return typeID;
}

class Component
{
public:
	Component() { }

	virtual void init() { }
	virtual void draw() { }
	virtual void update() { }
	
	virtual ~Component() { }

	Entity* m_entity;
};

class Entity
{
public:

	Entity() : m_id(++lastEntityID) { };

	int getID() const { return m_id; }

	bool isActive() const { return active; }

	void update() { for (auto& c : m_components) c->update(); }

	void draw() { for (auto& c : m_components) c->draw(); }

	void disable() { active = false; }

	template <typename T> bool hasComponent() const
	{
		return ComponentBitset[getComponentTypeID<T>()];
	}

	template <typename T, typename... TArgs> 
	T& addComponent(TArgs&&... cArgs)
	{
		T* c(new T(std::forward<TArgs>(cArgs)...));
		c->m_entity = const_cast<Entity*>(this);
		std::unique_ptr<Component> uPtr{ c };

		m_components.emplace_back(std::move(uPtr));
		m_componentArray[getComponentTypeID<T>()] = c;
		m_componentBitset[getComponentTypeID<T>()] = true;

		c->init();
		return *c;
	}

	template <typename T> T& getComponent() const
	{
		auto ptr(m_componentArray[getComponentTypeID<T>()]);
		return *static_cast<T*>(ptr);
	}



private:
	const int m_id;
	static int lastEntityID;
	bool active = true;
	std::vector<std::unique_ptr<Component>> m_components;

	ComponentArray m_componentArray;
	ComponentBitset m_componentBitset;
};

class EntityManager
{
public:
	void update() { for (auto& e : m_entities) e->update(); }

	void draw() { for (auto& e : m_entities) e->draw(); }

	void refresh() 
	{ 
		m_entities.erase(std::remove_if(m_entities.begin(), m_entities.end(),
			[](const std::unique_ptr<Entity>& m_entity) { return !m_entity->isActive(); }), m_entities.end());
	}

	Entity& addEntity()
	{
		Entity* e = new Entity();
		std::unique_ptr<Entity> uPtr{ e };
		m_entities.emplace_back(std::move(uPtr));

		return *e;
	}
private:
	std::vector<std::unique_ptr<Entity>> m_entities;
};

int Entity::lastEntityID = 0;