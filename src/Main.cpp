#include <iostream>
#include <cstdlib>
#include <SFML/System.hpp>

#include "Model.hpp"
#include "View.hpp"
#include "SFMLView.hpp"

using namespace std;

int main()
{
	Model* m = new Model();
	View* v = new SFMLView();

	v->setModel(m);

	while(v->run())
	{
		m->update();

		//synchronizes
		v->update();

		v->draw();

		sf::Sleep(0.001);
	}

	delete v;
	delete m;
	
	return EXIT_SUCCESS;
}
