#include "Model.hpp"

Model::Model()
{
	m_level = new Level();

	m_level->add(new Ship(500, 500));
	m_level->add(new Entity(100, 100));
	m_level->add(new Entity(100, 200));
}

Model::~Model()
{
	if(m_level != nullptr)
	{
		delete m_level;
	}
}

void Model::run()
{
	
}

void Model::update(float dt)
{
	//UPDATE LEVEL
	m_level->update(dt);
}

Level* Model::getLevel() const
{
	return m_level;
}

void Model::playerUp(bool ok, float dt)
{
	if(ok)
	{
		m_level->getPlayer()->move(0, dt);
	}
}

void Model::playerDown(bool ok, float dt)
{
	if(ok)
	{
		m_level->getPlayer()->move(1, dt);
	}
}

void Model::playerRight(bool ok, float dt)
{
	if(ok)
	{
		m_level->getPlayer()->move(2, dt);
	}
}

void Model::playerLeft(bool ok, float dt)
{
	if(ok)
	{
		m_level->getPlayer()->move(3, dt);
	}
}

Bullet* Model::playerFire(float dt)
{
	Bullet* b = m_level->getPlayer()->fire(dt);
	if(b != nullptr)
	{
	    m_level->add(b);
	    return b;
	}

    return nullptr;
}
