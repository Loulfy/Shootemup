#ifndef CSL_FRAME_H
#define CSL_FRAME_H

#include <iostream>

#include "Frame.hpp"

class CSLFrame : public Frame
{
	public:

		CSLFrame();
		CSLFrame(int x, int y, std::string name);
		~CSLFrame() override;
		void draw() override;
		void SetPosition(int x, int y);

	private:
	
	    float m_x;
	    float m_y;
	    std::string m_name;

};

#endif
