#include "Entity.hpp"

using namespace std;

Entity::Entity() : m_x(0), m_y(0), m_speed(2.f), m_firerate(1)
{

}

Entity::Entity(int x, int y) : m_x(x), m_y(y), m_speed(600.f), m_firerate(0.2), m_time(0)
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
	    return new Bullet(m_x, m_y - 64);
	}
	
	return nullptr;
}

void Entity::move(int dir, float dt)
{

}
