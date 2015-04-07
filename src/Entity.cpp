#include "Entity.hpp"

using namespace std;

Entity::Entity() : m_x(0), m_y(0)
{

}

Entity::Entity(int x, int y) : m_x(x), m_y(y)
{

}

Entity::~Entity()
{
	cout << "destruction entity" << endl;
}

int Entity::getX() const
{
	return m_x;
}

int Entity::getY() const
{
	return m_y;
}

Bullet* Entity::fire()
{
	cout << "FIRE !" << endl;
	return new Bullet(m_x, m_y - 10);
}

void Entity::move(int x, int y)
{
	m_x += x;
	m_y += y;
}
