#include "pch.h"
#include "Ellipse.h"

CEllipse::CEllipse(const RectD& ellipse, const CLineStyle& outlineStyle, const CStyle& fillStyle)
	: CShape(outlineStyle, fillStyle)
	, m_ellipse(ellipse)
{
}

std::optional<RectD> CEllipse::GetFrame() const
{
	return m_ellipse;
}

void CEllipse::SetFrame(const RectD& frame)
{
	m_ellipse = frame;
}

void CEllipse::DoDraw(ICanvas& canvas) const
{
	canvas.DrawEllipse(m_ellipse.GetLeftTop().x, m_ellipse.GetLeftTop().y, m_ellipse.GetWidth(), m_ellipse.GetHeight());
}