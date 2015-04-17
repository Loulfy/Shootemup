#ifndef MODEL_H
#define MODEL_H

#include <vector>

#include "Level.hpp"

class Model
{
	public:
		
		Model();
		~Model();
		void update(float dt);
		Level* getLevel() const;
		void playerUp(bool ok, float dt);
		void playerDown(bool ok, float dt);
		void playerRight(bool ok, float dt);
		void playerLeft(bool ok, float dt);
		Bullet* playerFire(float dt);

	private:

		Level* m_level;
};

#endif

