#pragma once

#include "Shape.h"
#include <vector>

class CRegularPolygon : public CShape
{
public:
	CRegularPolygon(int8_t vertexCount, const Point& center, double radius, Color color = Color::Black);

	void Draw(ICanvas& canvas) const override;

	int8_t GetVertexCount() const;
	Point GetCenter() const;
	double GetRadius() const;

private:
	int8_t m_vertexCount;
	Point m_center;
	double m_radius;
	std::vector<Point> m_vertices;

	void InitializeVertices();
};