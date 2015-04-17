#include "Entity.hpp"

using namespace std;

Entity::Entity() : m_x(0), m_y(0), m_speed(2.f), m_firerate(1)
{

}

Entity::Entity(float x, float y, int w, int h) : m_x(x), m_y(y), m_width(w), m_height(h), m_speed(600.f), m_firerate(0.05), m_time(0)
{

}

Entity::~Entity()
{
	cout << "destruction entity" << endl;
}

void Entity::update(float dt)
{
    //bonus
}

bool Entity::collide(Bullet* b)
{
	if (b->getX() < m_x + m_width && b->getX() + b->getWidth() > m_x && b->getY() < m_y + m_height && b->getHeight() + b->getY() > m_y)
	{
		return true;
	}

	return false;
}

int Entity::getX() const
{
	return m_x;
}

int Entity::getY() const
{
	return m_y;
}

Bullet* Entity::fire(float dt)
{
    m_time += dt;
    if(m_firerate < m_time)
    {
        m_time = 0;
	    return new Bullet(m_x, m_y - 64, 64, 64);
	}
	
	return nullptr;
}

void Entity::move(int dir, float dt)
{

}
