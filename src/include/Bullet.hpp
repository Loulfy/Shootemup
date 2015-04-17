#ifndef BULLET_H
#define BULLET_H

#include <vector>
#include <iostream>

class Bullet
{
	public:

		Bullet();
		Bullet(int x, int y, int w, int h);
		~Bullet();
		int getX() const;
		int getY() const;
		int getWidth() const;
		int getHeight() const;
		void update(float dt);

	private:

		float m_x;
		float m_y;

		int m_width;
		int m_height;
		
		float m_speed;

};

#endif
