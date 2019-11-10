#pragma once

#include "Style.h"

class CLineStyle : public CStyle
{
public:
	CLineStyle() = default;
	CLineStyle(bool enable, RGBAColor color = 0, double width = 1);

	std::optional<double> GetWidth() const;

private:
	std::optional<double> m_width;
};

bool operator!=(const CLineStyle &rational1, const CLineStyle &rational2);