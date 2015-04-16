#include "CSLFrame.hpp"

using namespace std;

CSLFrame::CSLFrame()
{

}

CSLFrame::CSLFrame(int x, int y, string name) : m_x(x), m_y(y), m_name(name)
{

}

CSLFrame::~CSLFrame()
{

}

void CSLFrame::SetPosition(int x, int y)
{
    m_x = x;
    m_y = y;
}

void CSLFrame::draw()
{
    cout << "Élément : "<< m_name << " en (" << m_x << ", " << m_y << ")" << endl;
}
