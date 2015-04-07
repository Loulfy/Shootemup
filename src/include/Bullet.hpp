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
		void update();

	private:

		int m_x;
		int m_y;

};

#endif
