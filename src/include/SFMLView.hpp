#ifndef VIEW_SFML_H
#define VIEW_SFML_H

#include <iostream>
#include <SFML/Graphics.hpp>

#include "View.hpp"
#include "SFMLFrame.hpp"
#include "AssetManager.hpp"

class SFMLView : public View
{
	public:

		SFMLView();
		~SFMLView();
		bool run() override;
		void setModel(Model* m) override;
		void draw() override;
		void update() override;
		void add(Bullet* bullet) override;
		void add(Entity* entity) override;

	private:

		sf::RenderWindow* m_window;
		sf::Clock m_clock;
		AssetManager m_assets;
};

#endif
