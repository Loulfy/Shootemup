#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <algorithm>

#include "Entity.hpp"
#include "Bullet.hpp"
#include "Ship.hpp"

class Level
{
	public:

		Level();
		~Level();
		void update(float dt);
		void add(Entity* e);
		void add(Bullet* b);
		void remove(Bullet* b);
		void remove(Entity* e);
		void add(Ship* player);
		int countEntity() const;
		int countBullet() const;
		Ship* getPlayer() const;
		Entity* getEntity(int i) const;
		Bullet* getBullet(int i) const;

	private:

		std::vector<Entity*> m_entities;
		std::vector<Bullet*> m_bullets;

};

#endif
