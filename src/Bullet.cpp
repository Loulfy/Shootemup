#include "Bullet.hpp"


Bullet::Bullet() : m_x(0), m_y(0)
{
	std::cout << "boum" << std::endl;
}

Bullet::Bullet(int x, int y) : m_x(x), m_y(y)
{
	std::cout << "boum" << std::endl;
}

Bullet::~Bullet()
{
	std::cout << "destruction bullet" << std::endl;
}

void Bullet::update()
{
	m_y -= 1;
}

int Bullet::getX() const
{
	return m_x;
}

int Bullet::getY() const
{
	return m_y;
}
