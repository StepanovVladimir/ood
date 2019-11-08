#pragma once

#include "CommonTypes.h"
#include <optional>

class CStyle
{
public:
	CStyle() = default;
	CStyle(bool enable, RGBAColor color = 0);

	std::optional<bool> IsEnabled() const;
	std::optional<RGBAColor> GetColor() const;

private:
	std::optional<bool> m_enable;
	std::optional<RGBAColor> m_color;
};