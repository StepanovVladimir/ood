#include "pch.h"
#include "Canvas.h"
#include <iostream>

using namespace std;

void CCanvas::SetColor(Color color)
{
	m_color = color;
}

void CCanvas::DrawLine(const Point& from, const Point& to)
{
	cout << ColorToString() << " line from (" << from.x << ", " << from.y << ") to (" << to.x << ", " << to.y << ")\n";
}

void CCanvas::DrawEllipse(const Point& center, double horizontalRadius, double verticalRadius)
{
	cout << ColorToString() << " ellipse with: center: (" << center.x << ", " << center.y << "); horizontal radius: "
		<< horizontalRadius << "; vertical radius: " << verticalRadius << endl;
}

string CCanvas::ColorToString() const
{
	switch (m_color)
	{
	case Color::Green:
		return "Green";

	case Color::Red:
		return "Red";

	case Color::Blue:
		return "Blue";

	case Color::Yellow:
		return "Yellow";

	case Color::Pink:
		return "Pink";

	default:
		return "Black";
	}
}