#include "Rectangle.h"
#include <stdexcept>

using namespace graphics_lib;

namespace shape_drawing_lib
{
	CRectangle::CRectangle(const Point& leftTop, int width, int height)
		: m_leftTop(leftTop)
		, m_width(width)
		, m_height(height)
	{
		if (m_width < 0 || m_height < 0)
		{
			throw std::invalid_argument("Width and height cannot be negative");
		}
	}

	void CRectangle::Draw(ICanvas& canvas) const
	{
		canvas.MoveTo(m_leftTop.x, m_leftTop.y);

		canvas.LineTo(m_leftTop.x + m_width, m_leftTop.y);
		canvas.LineTo(m_leftTop.x + m_width, m_leftTop.y + m_height);
		canvas.LineTo(m_leftTop.x, m_leftTop.y + m_height);
		canvas.LineTo(m_leftTop.x, m_leftTop.y);
	}
}