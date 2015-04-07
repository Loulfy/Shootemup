#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <iostream>

#include "Bullet.hpp"

class Entity
{
	public:

		Entity();
		Entity(int x, int y);
		virtual ~Entity();
		int getX() const;
		int getY() const;
		virtual void move(int x, int y);
		Bullet* fire();

	protected:

		int m_x;
		int m_y;
};

#endif
