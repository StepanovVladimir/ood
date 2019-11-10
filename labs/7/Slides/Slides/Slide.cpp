#include "pch.h"
#include "Slide.h"

CSlide::CSlide(double widht, double height, RGBAColor backgroundColor)
	: m_width(widht)
	, m_height(height)
	, m_backgroundColor(backgroundColor)
{
}

double CSlide::GetWidth() const
{
	return m_width;
}

double CSlide::GetHeight() const
{
	return m_height;
}

RGBAColor CSlide::GetBackgroundColor() const
{
	return m_backgroundColor;
}

void CSlide::SetBackgroundColor(RGBAColor color)
{
	m_backgroundColor = color;
}

void CSlide::Draw(ICanvas& canvas) const
{
	canvas.SetLineWidth(0);
	canvas.BeginFill(m_backgroundColor);
	canvas.MoveTo(0, 0);
	canvas.LineTo(m_width, 0);
	canvas.LineTo(m_width, m_height);
	canvas.LineTo(0, m_height);
	canvas.LineTo(0, 0);
	canvas.EndFill();
	for (size_t i = 0; i < GetShapesCount(); ++i)
	{
		GetShapeAtIndex(i)->Draw(canvas);
	}
}