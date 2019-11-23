#include "pch.h"
#include "Rectangle.h"

CRectangle::CRectangle(const RectD& rect, const CLineStyle& outlineStyle, const CStyle& fillStyle)
	: CShape(outlineStyle, fillStyle)
	, m_rect(rect)
{
}

std::optional<RectD> CRectangle::GetFrame() const
{
	return m_rect;
}

void CRectangle::SetFrame(const RectD& frame)
{
	m_rect = frame;
}

void CRectangle::DoDraw(ICanvas& canvas) const
{
	canvas.MoveTo(m_rect.GetLeftTop().x, m_rect.GetLeftTop().y);
	canvas.LineTo(m_rect.GetLeftTop().x + m_rect.GetWidth(), m_rect.GetLeftTop().y);
	canvas.LineTo(m_rect.GetLeftTop().x + m_rect.GetWidth(), m_rect.GetLeftTop().y + m_rect.GetHeight());
	canvas.LineTo(m_rect.GetLeftTop().x, m_rect.GetLeftTop().y + m_rect.GetHeight());
	canvas.LineTo(m_rect.GetLeftTop().x, m_rect.GetLeftTop().y);
}