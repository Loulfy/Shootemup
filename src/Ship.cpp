#include "Ship.hpp"

Ship::Ship() : Entity()
{

}

Ship::Ship(float x, float y, int w, int h) : Entity(x, y, w, h)
{

}

Ship::~Ship()
{

}

void Ship::move(int dir, float dt)
{
    switch(dir)
    {
        case 0:
            m_y -= m_speed * dt;
            break;
        case 1:
            m_y += m_speed * dt;
            break;
        case 2:
            m_x += m_speed * dt;
            break;
        case 3:
            m_x -= m_speed * dt;
            break;
            
        default:
            break;
    }
}
