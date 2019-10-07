#include "MockCanvas.h"

using namespace std;

void CMockCanvas::SetColor(Color color)
{
	m_color = color;
}

void CMockCanvas::DrawLine(const Point& from, const Point& to)
{
	m_lines.push_back({ from, to, m_color });
}

void CMockCanvas::DrawEllipse(const Point& leftTop, double width, double height)
{
	m_ellipses.push_back({ leftTop, width, height, m_color });
}

const vector<CMockCanvas::Line>& CMockCanvas::GetLines() const
{
	return m_lines;
}

const vector<CMockCanvas::Ellipse>& CMockCanvas::GetEllipses() const
{
	return m_ellipses;
}