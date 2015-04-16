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
		void update(float dt);
		int getX() const;
		int getY() const;
		virtual void move(int dir, float dt);
		Bullet* fire(float dt);

	protected:

		float m_x;
		float m_y;

        float m_speed;
		float m_firerate;
		float m_time;
};

#endif
