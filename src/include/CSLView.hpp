#ifndef VIEW_CSL_H
#define VIEW_CSL_H

#include <iostream>
#include <ctime>

#include "View.hpp"
#include "CSLFrame.hpp"

class CSLView : public View
{
	public:

		CSLView();
		~CSLView();
		bool run() override;
		void setModel(Model* m) override;
		void draw() override;
		void update() override;
		void add(Bullet* bullet) override;
		void add(Entity* entity) override;

	private:
	
	    std::clock_t m_clock;

};

#endif
