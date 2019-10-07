#pragma once

#include "../Factory/ICanvas.h"
#include <vector>

class CMockCanvas : public ICanvas
{
public:
	struct Line
	{
		Point from;
		Point to;
		Color color;
	};

	struct Ellipse
	{
		Point leftTop;
		double width;
		double height;
		Color color;
	};

	void SetColor(Color color) override;
	void DrawLine(const Point& from, const Point& to) override;
	void DrawEllipse(const Point& leftTop, double width, double height) override;

	const std::vector<Line>& GetLines() const;
	const std::vector<Ellipse>& GetEllipses() const;

private:
	Color m_color = Color::Black;
	std::vector<Line> m_lines;
	std::vector<Ellipse> m_ellipses;
};