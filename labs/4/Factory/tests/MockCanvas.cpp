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

void CMockCanvas::DrawEllipse(const Point& center, double horizontalRadius, double verticalRadius)
{
	m_ellipses.push_back({ center, horizontalRadius, verticalRadius, m_color });
}

const vector<CMockCanvas::Line>& CMockCanvas::GetLines() const
{
	return m_lines;
}

const vector<CMockCanvas::Ellipse>& CMockCanvas::GetEllipses() const
{
	return m_ellipses;
}

bool RealNumbersIsEqual(double num1, double num2)
{
	return num1 - FLT_EPSILON < num2 && num1 + FLT_EPSILON > num2;
}

bool operator==(const Point& p1, const Point& p2)
{
	return RealNumbersIsEqual(p1.x, p2.x) && RealNumbersIsEqual(p1.y, p2.y);
}