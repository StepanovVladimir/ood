#pragma once

#include "Shapes.h"
#include <set>

class CSlide : public CShapes, public IDrawable
{
public:
	CSlide(double widht, double height, RGBAColor backgroundColor = 0);

	double GetWidth() const;
	double GetHeight() const;

	RGBAColor GetBackgroundColor() const;
	void SetBackgroundColor(RGBAColor color);

	void CreateGroup(const std::set<size_t>& indexes);
	void Ungroup(size_t index);

	void Draw(ICanvas& canvas) const override;

private:
	double m_width;
	double m_height;
	RGBAColor m_backgroundColor;
};