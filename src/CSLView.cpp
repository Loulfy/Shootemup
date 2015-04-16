#include "CSLView.hpp"

using namespace std;

CSLView::CSLView()
{

}

CSLView::~CSLView()
{
	for(auto f : m_entity_frames)
	{
		delete f.second;
	}

	for(auto f : m_bullet_frames)
	{
		delete f.second;
	}
}

void CSLView::setModel(Model* m)
{
	View::setModel(m);

	Level* level = m->getLevel();

	for(int i = 0; i < level->countEntity(); ++i)
	{
		Entity* e = level->getEntity(i);
		this->add(e);
	}
}

void CSLView::add(Entity* entity)
{
    Ship* player = dynamic_cast<Ship*>(entity);
    if(player != nullptr)
    {
	    m_entity_frames[entity] = new CSLFrame(entity->getX(), entity->getY(), "Player");
	}
	else
	{
	    m_entity_frames[entity] = new CSLFrame(entity->getX(), entity->getY(), "Enemy");
	}
}

void CSLView::add(Bullet* bullet)
{
	m_bullet_frames[bullet] = new CSLFrame(bullet->getX(), bullet->getY(), "Bullet");		
}

void CSLView::update()
{
    //CLOCK
    float dt = ((float)m_clock)/CLOCKS_PER_SEC;
    m_clock = clock();
    
    //UPDATE MODEL with delta time !
    m_model->update(dt);
    
	//KEYBOARD
	/*
	const sf::Input& Input = m_window->GetInput();

	m_model->playerUp(Input.IsKeyDown(sf::Key::Up), dt);
	m_model->playerDown(Input.IsKeyDown(sf::Key::Down), dt);
	m_model->playerRight(Input.IsKeyDown(sf::Key::Right), dt);
	m_model->playerLeft(Input.IsKeyDown(sf::Key::Left), dt);

	if(Input.IsKeyDown(sf::Key::Space))
	{
		Bullet* b = m_model->playerFire(dt);
		if(b != nullptr)
		    this->add(b);
	}
	*/

	//SYNCHRONIZES ENTITY
	for(auto f : m_entity_frames)
	{
		CSLFrame* frame = dynamic_cast<CSLFrame*>(f.second);
		frame->SetPosition(f.first->getX(), f.first->getY());
	}

	//SYNCHRONIZES BULLET
	for(auto f : m_bullet_frames)
	{
	    if(f.first->getY() < 0)
	    {
	        m_bullet_frames.erase(f.first);
	        m_model->getLevel()->remove(f.first);
	        delete f.first;
	        delete f.second;
	    }
	    else
	    {
		    CSLFrame* frame = dynamic_cast<CSLFrame*>(f.second);
		    frame->SetPosition(f.first->getX(), f.first->getY());
		}
	}
}

bool CSLView::run()
{
    float dt = ((float)m_clock)/CLOCKS_PER_SEC;

    int cmd;
    cin >> cmd;
    switch(cmd)
    {
        case 0:
            {
                Bullet* b = m_model->playerFire(dt);
		        if(b != nullptr)
		        {
		            this->add(b);
		        }
		    }
            break;
            
        case 2:
            {
                m_model->getLevel()->getPlayer()->move(2, dt);
                break;
            }
            
       case 3:
            {
                m_model->getLevel()->getPlayer()->move(3, dt);
                break;
            }
            
        default:
            break;
    }
	return true;
}

void CSLView::draw()
{
	if(system("clear") == 1)
	{
	    cout << "Echec Clear !" << endl;
	}
	cout << m_clock << endl;
	
	cout << "0. Tirez" << endl;
	cout << "2. Aller à droite" << endl;
	cout << "3. Aller à gauche" << endl;
	

	for(auto frame : m_entity_frames)
	{
		frame.second->draw();
	}
	
	for(auto frame : m_bullet_frames)
	{
		frame.second->draw();
	}	
}
