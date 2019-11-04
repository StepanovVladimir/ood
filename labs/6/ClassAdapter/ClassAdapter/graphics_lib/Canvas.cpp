#include "Canvas.h"
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

namespace graphics_lib
{
	void CCanvas::SetColor(uint32_t rgbColor)
	{
		ostringstream strm;
		strm << setfill('0') << setw(6) << hex << (rgbColor & 0xffffff);
		cout << "SetColor (#" << strm.str() << ')' << endl;
	}

	void CCanvas::MoveTo(int x, int y)
	{
		cout << "MoveTo (" << x << ", " << y << ")" << endl;
	}

	void CCanvas::LineTo(int x, int y)
	{
		cout << "LineTo (" << x << ", " << y << ")" << endl;
	}
}