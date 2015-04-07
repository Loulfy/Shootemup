#include "Ship.hpp"

Ship::Ship() : Entity()
{

}

Ship::Ship(int x, int y) : Entity(x, y)
{

}

Ship::~Ship()
{

}

void Ship::move(int x, int y)
{
	m_x += x;
	m_y += y;
}
