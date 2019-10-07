#pragma once

#include "ICanvas.h"
#include <string>

class CCanvas : public ICanvas
{
public:
	void SetColor(Color color) override;
	void DrawLine(const Point& from, const Point& to) override;
	void DrawEllipse(const Point& leftTop, double width, double height) override;

private:
	Color m_color = Color::Black;

	std::string ColorToString() const;
};