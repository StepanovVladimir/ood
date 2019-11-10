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

bool operator!=(const CStyle &rational1, const CStyle &rational2)
{
	return rational1.IsEnabled() != rational2.IsEnabled() || rational1.GetColor() != rational2.GetColor();
}