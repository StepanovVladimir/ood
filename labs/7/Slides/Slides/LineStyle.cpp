#include "pch.h"
#include "LineStyle.h"

using namespace std;

CLineStyle::CLineStyle(bool enable, RGBAColor color, double width)
	: CStyle(enable, color)
	, m_width(width)
{
	if (m_width < 0)
	{
		invalid_argument("The line width cannot be negative");
	}
}

optional<double> CLineStyle::GetWidth() const
{
	return m_width;
}

bool operator!=(const CLineStyle &rational1, const CLineStyle &rational2)
{
	return rational1.IsEnabled() != rational2.IsEnabled() || rational1.GetColor() != rational2.GetColor()
		|| rational1.GetWidth() != rational2.GetWidth();
}