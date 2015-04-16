#ifndef BULLET_H
#define BULLET_H

#include <vector>
#include <iostream>

class Bullet
{
	public:

		Bullet();
		Bullet(int x, int y);
		~Bullet();
		int getX() const;
		int getY() const;
		void update(float dt);

	private:

		float m_x;
		float m_y;
		
		float m_speed;

};

#endif
