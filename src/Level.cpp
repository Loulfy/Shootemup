#include "Level.hpp"

Level::Level()
{

}

Level::~Level()
{
	for(auto e : m_entities)
	{
		delete e;
	}

	for(auto b : m_bullets)
	{
		delete b;
	}
}

void Level::add(Entity* e)
{
	m_entities.push_back(e);
}

void Level::add(Bullet* b)
{
	m_bullets.push_back(b);
}

void Level::add(Ship* player)
{
	m_entities.push_back(player);
}

int Level::countEntity() const
{
	return m_entities.size();
}

int Level::countBullet() const
{
	return m_bullets.size();
}

Entity* Level::getEntity(int i) const
{
	return m_entities[i];
}

Bullet* Level::getBullet(int i) const
{
	return m_bullets[i];
}

Ship* Level::getPlayer() const
{
	for(auto e : m_entities)
	{
		Ship* player = dynamic_cast<Ship*>(e);
		if(player != nullptr)
		{
			return player;
		}
	}

	return nullptr;
}