#pragma once

#include "Shape.h"

class CTriangle : public CShape
{
public:
	CTriangle(const Point& vertex1, const Point& vertex2, const Point& vertex3, Color color = Color::Black);

	void Draw(ICanvas& canvas) const override;

	Point GetVertex1() const;
	Point GetVertex2() const;
	Point GetVertex3() const;

private:
	Point m_vertex1;
	Point m_vertex2;
	Point m_vertex3;
};