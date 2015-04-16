#ifndef SHIP_H
#define SHIP_H

#include <iostream>

#include "Entity.hpp"

class Ship : public Entity
{
	public:

		Ship();
		Ship(int x, int y);
		~Ship() override;
		void move(int dir, float dt) override; 

	private:

};

#endif
