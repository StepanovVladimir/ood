#pragma once

#include "Shapes.h"

class CSlide : public CShapes, public IDrawable
{
public:
	CSlide(double widht, double height, RGBAColor backgroundColor = 0);

	double GetWidth() const;
	double GetHeight() const;

	RGBAColor GetBackgroundColor() const;
	void SetBackgroundColor(RGBAColor color);

	void Draw(ICanvas& canvas) const override;

private:
	double m_width;
	double m_height;
	RGBAColor m_backgroundColor;
};