#include "pch.h"
#include "Rectangle.h"
#include <stdexcept>

CRectangle::CRectangle(const Point& leftTop, const Point& rightBottom, Color color)
	: CShape(color)
{
	if (leftTop.x > rightBottom.x || leftTop.y > rightBottom.y)
	{
		throw std::runtime_error("Cannot create a rectangle, invalid location of left top and right bottom vertices");
	}
	m_leftTop = leftTop;
	m_rightBottom = rightBottom;
}

void CRectangle::Draw(ICanvas& canvas) const
{
	canvas.SetColor(GetColor());

	Point leftBottom{ m_leftTop.x, m_rightBottom.y };
	Point rightTop{ m_rightBottom.x, m_leftTop.y };

	canvas.DrawLine(m_leftTop, rightTop);
	canvas.DrawLine(rightTop, m_rightBottom);
	canvas.DrawLine(m_rightBottom, leftBottom);
	canvas.DrawLine(leftBottom, m_leftTop);
}

Point CRectangle::GetLeftTop() const
{
	return m_leftTop;
}

Point CRectangle::GetRightBottom() const
{
	return m_rightBottom;
}