#include <iostream>
#include <cstdlib>
#include <SFML/System.hpp>

#include "Model.hpp"
#include "View.hpp"
#include "SFMLView.hpp"
#include "CSLView.hpp"

using namespace std;

int main()
{
	Model* m = new Model();
	//View* v = new CSLView();
	View* v = new SFMLView();

	v->setModel(m);

	while(v->run())
	{
		v->update();

		v->draw();
	}

	delete v;
	delete m;
	
	return EXIT_SUCCESS;
}
