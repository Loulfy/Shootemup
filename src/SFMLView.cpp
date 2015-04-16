#include "SFMLView.hpp"

using namespace std;
using namespace sf;

SFMLView::SFMLView()
{
	m_window = new sf::RenderWindow(sf::VideoMode(800, 600, 32), "Shmup", sf::Style::Close);
	m_window->SetFramerateLimit(60);

	m_assets.add("assets/copyright.png");
}

SFMLView::~SFMLView()
{
	delete m_window;

	for(auto f : m_entity_frames)
	{
		delete f.second;
	}

	for(auto f : m_bullet_frames)
	{
		delete f.second;
	}
}

void SFMLView::setModel(Model* m)
{
	View::setModel(m);

	Level* level = m->getLevel();

	for(int i = 0; i < level->countEntity(); ++i)
	{
		Entity* e = level->getEntity(i);
		this->add(e);
	}
}

void SFMLView::add(Entity* entity)
{
	m_entity_frames[entity] = new SFMLFrame(entity->getX(), entity->getY(), m_assets.get("assets/copyright.png"));

	SFMLFrame* frame = dynamic_cast<SFMLFrame*>(m_entity_frames[entity]);
	if(frame != nullptr)
	{
		frame->setWindow(m_window);
		frame->setRegion(IntRect(0, 0, 64, 64));
	}	
}

void SFMLView::add(Bullet* bullet)
{
	m_bullet_frames[bullet] = new SFMLFrame(bullet->getX(), bullet->getY(), m_assets.get("assets/copyright.png"));

	SFMLFrame* frame = dynamic_cast<SFMLFrame*>(m_bullet_frames[bullet]);
	if(frame != nullptr)
	{
		frame->setWindow(m_window);
		frame->setRegion(IntRect(64, 0, 128, 64));
	}		
}

void SFMLView::update()
{
    //CLOCK
    float dt = m_clock.GetElapsedTime();
    m_clock.Reset();
    
    //UPDATE MODEL with delta time !
    m_model->update(dt);
    
	//KEYBOARD
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

	//SYNCHRONIZES ENTITY
	for(auto f : m_entity_frames)
	{
		SFMLFrame* frame = dynamic_cast<SFMLFrame*>(f.second);
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
		    SFMLFrame* frame = dynamic_cast<SFMLFrame*>(f.second);
		    frame->SetPosition(f.first->getX(), f.first->getY());
		}
	}
}

bool SFMLView::run()
{
	bool result = false;
	if(m_window->IsOpened())
	{
    	result = true;
    	Event event;
    	while (m_window->GetEvent(event))
		{
			switch(event.Type)
			{
				case Event::Closed:
					m_window->Close();
					result = false;
					break;


				default:
					break;
      		}
    	}
	}  

	return result;
}

void SFMLView::draw()
{
	m_window->Clear(Color::White);

	for(auto frame : m_entity_frames)
	{
		frame.second->draw();
	}
	
	for(auto frame : m_bullet_frames)
	{
		frame.second->draw();
	}	

	m_window->Display();
}
