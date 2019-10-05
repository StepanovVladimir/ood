#pragma once

#include "Shape.h"

class CRectangle : public CShape
{
public:
	CRectangle(const Point& leftTop, const Point& rightBottom, Color color = Color::Black);

	void Draw(ICanvas& canvas) const override;

	Point GetLeftTop() const;
	Point GetRightBottom() const;

private:
	Point m_leftTop;
	Point m_rightBottom;
};