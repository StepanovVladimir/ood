#pragma once

#include "Shapes.h"

class CSlide : public CShapes, public IDrawable
{
public:
	double GetWidth() const;
	double GetHeight() const;

	RGBAColor GetBackgroundColor() const;
	void SetBackgroundColor(RGBAColor color);

	void Draw(ICanvas& canvas) const override;
};