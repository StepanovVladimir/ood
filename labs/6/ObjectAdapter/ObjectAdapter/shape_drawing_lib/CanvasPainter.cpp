#include "CanvasPainter.h"

using namespace graphics_lib;

namespace shape_drawing_lib
{
	CCanvasPainter::CCanvasPainter(ICanvas& canvas)
		: m_canvas(canvas)
	{
	}

	void CCanvasPainter::Draw(const ICanvasDrawable& drawable)
	{
		drawable.Draw(m_canvas);
	}
}