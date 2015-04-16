#include "Ship.hpp"

Ship::Ship() : Entity()
{

}

Ship::Ship(int x, int y) : Entity(x, y)
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
