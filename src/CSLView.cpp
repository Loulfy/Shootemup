#include "CSLView.hpp"

using namespace std;

CSLView::CSLView()
{

}

CSLView::~CSLView()
{
	//Supprime toute les objets frame.
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
	
	//Initialisation
	for(int i = 0; i < level->countEntity(); ++i)
	{
		Entity* e = level->getEntity(i);
		this->add(e);
	}

	this->draw();
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
	//Pour la vue console l'horloge est fixe.
	float dt = 0.1;
    
    //UPDATE MODEL with delta time !
    m_model->update(dt);

	//SYNCHRONIZES ENTITY
	for(auto f : m_entity_frames)
	{
		CSLFrame* frame = dynamic_cast<CSLFrame*>(f.second);
		frame->SetPosition(f.first->getX(), f.first->getY());

		for(auto b : m_bullet_frames)
		{
			//Test collision des missiles avec les entités ennemies.
			if(f.first->collide(b.first))
			{
				//Si oui on supprime l'ennemie et le missile.
				m_bullet_frames.erase(b.first);
	       		m_model->getLevel()->remove(b.first);
	     	    delete b.first;
	      	    delete b.second;

				m_entity_frames.erase(f.first);
	       		m_model->getLevel()->remove(f.first);
	     	    delete f.first;
	      	    delete f.second;
			}
		}
	}

	//SYNCHRONIZES BULLET
	for(auto f : m_bullet_frames)
	{
		//Test si les missiles sortent de l'écran
	    if(f.first->getY() < 0)
	    {
			//Si oui on supprime le missile.
	        m_bullet_frames.erase(f.first);
	        m_model->getLevel()->remove(f.first);
	        delete f.first;
	        delete f.second;
	    }
	    else
	    {
			//Sinon on met à jours.
		    CSLFrame* frame = dynamic_cast<CSLFrame*>(f.second);
		    frame->SetPosition(f.first->getX(), f.first->getY());
		}
	}
}

bool CSLView::run()
{
	float dt = 0.1;

    int cmd;
    cin >> cmd;
    switch(cmd)
    {
        case 1:
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
            }
			break;
            
       case 3:
            {
                m_model->getLevel()->getPlayer()->move(3, dt);
            }
			break;

		case 6:
            {
                return false;
            }
			break;
            
        default:
            break;
    }
	return true;
}

void CSLView::draw()
{
	if(system("clear") == 1)
	{
	    cout << "Echec Clear : remplacer 'clear' par 'cls' !" << endl;
	}
	
	cout << "---- Commande ----" << endl;
	cout << "0. Rafraichir" << endl;
	cout << "1. Tirer" << endl;
	cout << "2. Aller à droite" << endl;
	cout << "3. Aller à gauche" << endl;
	cout << "6. Quitter" << endl;
	cout << "------------------" << endl;
	

	for(auto frame : m_entity_frames)
	{
		frame.second->draw();
	}
	
	for(auto frame : m_bullet_frames)
	{
		frame.second->draw();
	}	
}
