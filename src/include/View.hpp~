#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <map>

#include "Model.hpp"
#include "Level.hpp"
#include "Frame.hpp"

class View
{
	public:

		View();
		virtual ~View();
		virtual void setModel(Model* m);
		virtual bool run();
		virtual void draw();
		virtual void update();
		virtual void add(Bullet* bullet);
		virtual void add(Entity* entity);

	protected:

		Model* m_model;

		std::map<Entity*, Frame*> m_entity_frames;
		std::map<Bullet*, Frame*> m_bullet_frames;

};

#endif
