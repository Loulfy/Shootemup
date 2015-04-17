#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <iostream>

#include "Bullet.hpp"

class Entity
{
	public:

		Entity();
		Entity(float x, float y, int w, int h);
		virtual ~Entity();
		void update(float dt);
		bool collide(Bullet* b);
		int getX() const;
		int getY() const;
		virtual void move(int dir, float dt);
		Bullet* fire(float dt);

	protected:

		float m_x;
		float m_y;

		int m_width;
		int m_height;

        float m_speed;
		float m_firerate;
		float m_time;
};

#endif
