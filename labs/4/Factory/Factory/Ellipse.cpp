#include "pch.h"
#include "Ellipse.h"
#include <stdexcept>

CEllipse::CEllipse(const Point& center, double horizontalRadius, double verticalRadius, Color color)
	: CShape(color)
	, m_center(center)
{
	if (horizontalRadius < 0 || verticalRadius < 0)
	{
		throw std::runtime_error("Cannot create a ellipse, the radius cannot be negative");
	}
	m_horizontalRadius = horizontalRadius;
	m_verticalRadius = verticalRadius;
}

void CEllipse::Draw(ICanvas& canvas) const
{
	canvas.SetColor(GetColor());

	canvas.DrawEllipse(m_center, m_horizontalRadius, m_verticalRadius);
}

Point CEllipse::GetCenter() const
{
	return m_center;
}

double CEllipse::GetHorizontalRadius() const
{
	return m_horizontalRadius;
}

double CEllipse::GetVerticalRadius() const
{
	return m_verticalRadius;
}