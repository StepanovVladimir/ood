#include "pch.h"
#include "RegularPolygon.h"
#define _USE_MATH_DEFINES
#include <math.h>

CRegularPolygon::CRegularPolygon(int8_t verticesCount, const Point& center, double radius, Color color)
	: CShape(color)
	, m_center(center)
{
	if (verticesCount < 3)
	{
		throw std::invalid_argument("Cannot create a regular polygon, the number of vertices must be at least three");
	}
	if (radius < 0)
	{
		throw std::invalid_argument("Cannot create a regular polygon, the radius cannot be negative");
	}
	m_radius = radius;
	InitializeVertices(verticesCount);
}

void CRegularPolygon::Draw(ICanvas& canvas) const
{
	canvas.SetColor(GetColor());

	for (size_t i = 0; i < m_vertices.size(); i++)
	{
		if (i + 1 < m_vertices.size())
		{
			canvas.DrawLine(m_vertices[i], m_vertices[i + 1]);
		}
		else
		{
			canvas.DrawLine(m_vertices[i], m_vertices[0]);
		}
	}
}

int8_t CRegularPolygon::GetVerticesCount() const
{
	return (int8_t)m_vertices.size();
}

Point CRegularPolygon::GetCenter() const
{
	return m_center;
}

double CRegularPolygon::GetRadius() const
{
	return m_radius;
}

void CRegularPolygon::InitializeVertices(int8_t verticesCount)
{
	double angleBetweenVertices = 2 * M_PI / verticesCount;
	for (int8_t i = 0; i < verticesCount; i++)
	{
		Point vertex;
		vertex.x = m_center.x + m_radius * sin(i * angleBetweenVertices);
		vertex.y = m_center.y - m_radius * cos(i * angleBetweenVertices);
		m_vertices.push_back(vertex);
	}
}