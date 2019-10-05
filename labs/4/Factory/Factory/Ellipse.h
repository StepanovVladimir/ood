#pragma once

#include "Shape.h"

class CEllipse : public CShape
{
public:
	CEllipse(const Point& center, double horizontalRadius, double verticalRadius, Color color = Color::Black);
	
	void Draw(ICanvas& canvas) const override;

	Point GetCenter() const;
	double GetHorizontalRadius() const;
	double GetVerticalRadius() const;

private:
	Point m_center;
	double m_horizontalRadius;
	double m_verticalRadius;
};