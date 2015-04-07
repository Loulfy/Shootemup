#include "Model.hpp"

Model::Model()
{
	m_level = new Level();

	m_level->add(new Ship(500, 500));
	m_level->add(new Entity(100, 100));
	m_level->add(new Entity(100, 200));

	//m_level->add(player->fire());
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

void Model::update()
{
	//UPDATE BULLETS
	for(int i = 0; i < m_level->countBullet(); ++i)
	{
		m_level->getBullet(i)->update();
	}
}

Level* Model::getLevel() const
{
	return m_level;
}

void Model::playerUp(bool ok)
{
	if(ok)
	{
		m_level->getPlayer()->move(0,-1);
	}
}

void Model::playerDown(bool ok)
{
	if(ok)
	{
		m_level->getPlayer()->move(0, 1);
	}
}

void Model::playerRight(bool ok)
{
	if(ok)
	{
		m_level->getPlayer()->move(1, 0);
	}
}

void Model::playerLeft(bool ok)
{
	if(ok)
	{
		m_level->getPlayer()->move(-1, 0);
	}
}

void Model::playerFire(bool ok)
{
	if(ok)
	{
		m_level->add(m_level->getPlayer()->fire());
	}
}
