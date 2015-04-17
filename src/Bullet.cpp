#include "Bullet.hpp"


Bullet::Bullet() : m_x(0), m_y(0), m_width(0), m_height(0), m_speed(400.f)
{

}

Bullet::Bullet(int x, int y, int w, int h) : m_x(x), m_y(y), m_width(w), m_height(h), m_speed(800.f)
{

}

Bullet::~Bullet()
{
	//std::cout << "destruction bullet" << std::endl;
}

void Bullet::update(float dt)
{
	m_y -= m_speed * dt;
}

int Bullet::getX() const
{
	return m_x;
}

int Bullet::getY() const
{
	return m_y;
}

int Bullet::getWidth() const
{
	return m_width;
}

int Bullet::getHeight() const
{
	return m_height;
}
