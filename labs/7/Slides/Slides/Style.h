#pragma once

#include "CommonTypes.h"
#include <optional>

class CStyle
{
public:
	CStyle() = default;
	CStyle(bool enable, RGBAColor color = 0xff);

	std::optional<bool> IsEnabled() const;
	std::optional<RGBAColor> GetColor() const;

private:
	std::optional<bool> m_enable;
	std::optional<RGBAColor> m_color;
};

bool operator==(const CStyle &style1, const CStyle &style2);
bool operator!=(const CStyle &style1, const CStyle &style2);