#include "pch.h"
#include "Triangle.h"
#include <algorithm>

using namespace std;

CTriangle::CTriangle(const PointD& p1, const PointD& p2, const PointD& p3,
	const CLineStyle& outlineStyle, const CStyle& fillStyle)
	: CShape(outlineStyle, fillStyle)
	, m_p1(p1)
	, m_p2(p2)
	, m_p3(p3)
	, m_frame(CreateFrame())
{
	m_relativeP1.x = (m_p1.x - m_frame.GetLeftTop().x) / m_frame.GetWidth();
	m_relativeP1.y = (m_p1.y - m_frame.GetLeftTop().y) / m_frame.GetHeight();
	m_relativeP2.x = (m_p2.x - m_frame.GetLeftTop().x) / m_frame.GetWidth();
	m_relativeP2.y = (m_p2.y - m_frame.GetLeftTop().y) / m_frame.GetHeight();
	m_relativeP3.x = (m_p3.x - m_frame.GetLeftTop().x) / m_frame.GetWidth();
	m_relativeP3.y = (m_p3.y - m_frame.GetLeftTop().y) / m_frame.GetHeight();
}

RectD CTriangle::GetFrame() const
{
	return m_frame;
}

void CTriangle::SetFrame(const RectD& frame)
{
	m_frame = frame;

	m_p1.x = m_frame.GetLeftTop().x + m_relativeP1.x * m_frame.GetWidth();
	m_p1.y = m_frame.GetLeftTop().y + m_relativeP1.y * m_frame.GetHeight();
	m_p2.x = m_frame.GetLeftTop().x + m_relativeP2.x * m_frame.GetWidth();
	m_p2.y = m_frame.GetLeftTop().y + m_relativeP2.y * m_frame.GetHeight();
	m_p3.x = m_frame.GetLeftTop().x + m_relativeP3.x * m_frame.GetWidth();
	m_p3.y = m_frame.GetLeftTop().y + m_relativeP3.y * m_frame.GetHeight();
}

void CTriangle::DoDraw(ICanvas& canvas) const
{
	canvas.MoveTo(m_p1.x, m_p1.y);
	canvas.LineTo(m_p2.x, m_p2.y);
	canvas.LineTo(m_p3.x, m_p3.y);
	canvas.LineTo(m_p1.x, m_p1.y);
}

RectD CTriangle::CreateFrame() const
{
	double left = min(min(m_p1.x, m_p2.x), m_p3.x);
	double top = min(min(m_p1.y, m_p2.y), m_p3.y);
	double width = max(max(m_p1.x, m_p2.x), m_p3.x) - left;
	double height = max(max(m_p1.y, m_p2.y), m_p3.y) - top;
	return RectD({ left, top }, width, height);
}