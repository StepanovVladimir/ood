#include "pch.h"
#include "Style.h"

using namespace std;

CStyle::CStyle(bool enable, RGBAColor color)
	: m_enable(enable)
	, m_color(color)
{
}

optional<bool> CStyle::IsEnabled() const
{
	return m_enable;
}

optional<RGBAColor> CStyle::GetColor() const
{
	return m_color;
}

bool operator==(const CStyle &style1, const CStyle &style2)
{
	return style1.IsEnabled() == style2.IsEnabled() && style1.GetColor() == style2.GetColor();
}

bool operator!=(const CStyle &style1, const CStyle &style2)
{
	return !(style1 == style2);
}