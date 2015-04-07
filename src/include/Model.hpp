#ifndef MODEL_H
#define MODEL_H

#include <vector>

#include "Level.hpp"

class Model
{
	public:
		
		Model();
		~Model();
		void run();
		void update();
		Level* getLevel() const;
		void playerUp(bool ok);
		void playerDown(bool ok);
		void playerRight(bool ok);
		void playerLeft(bool ok);
		void playerFire(bool ok);

	private:

		Level* m_level;
};

#endif

