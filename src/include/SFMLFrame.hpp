#ifndef SFML_FRAME_H
#define SFML_FRAME_H

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Frame.hpp"

class SFMLFrame : public Frame, public sf::Sprite
{
	public:

		SFMLFrame();
		~SFMLFrame() override;
		SFMLFrame(int x, int y, sf::Image* img);
		void setRegion(sf::IntRect tile);
		void setWindow(sf::RenderWindow* window);
		void draw() override;

	private:

		sf::RenderWindow* m_window;
};

#endif
