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