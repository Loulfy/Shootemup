#include "SFMLFrame.hpp"

using namespace sf;

SFMLFrame::SFMLFrame() : Sprite()
{

}

SFMLFrame::SFMLFrame(int x, int y, Image* img) : Sprite(*img)
{
	this->SetPosition(x, y);
}

SFMLFrame::~SFMLFrame()
{

}

void SFMLFrame::setRegion(IntRect tile)
{
	this->SetSubRect(tile);
}

void SFMLFrame::setWindow(sf::RenderWindow* window)
{
	m_window = window;
}

void SFMLFrame::draw()
{
	m_window->Draw(*this);
}
