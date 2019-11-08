#include "pch.h"
#include "Shape.h"
#include <stdexcept>

CShape::CShape(const CLineStyle& outlineStyle, const CStyle& fillStyle)
	: m_outlineStyle(outlineStyle)
	, m_fillStyle(fillStyle)
{
	if (!m_outlineStyle.GetColor() || !m_fillStyle.GetColor())
	{
		throw std::invalid_argument("Only non nullopt values should be passed");
	}
}

const CLineStyle& CShape::GetOutlineStyle() const
{
	return m_outlineStyle;
}

void CShape::SetOutlineStyle(const CLineStyle& outlineStyle)
{
	m_outlineStyle = outlineStyle;
}

const CStyle& CShape::GetFillStyle() const
{
	return m_fillStyle;
}

void CShape::SetFillStyle(const CStyle& fillStyle)
{
	m_fillStyle = fillStyle;
}

CGroupShape* CShape::GetGroup()
{
	return nullptr;
}
const CGroupShape* CShape::GetGroup() const
{
	return nullptr;
}

void CShape::Draw(ICanvas& canvas) const
{
	canvas.SetLineColor(m_outlineStyle.GetColor().value());
	if (!m_outlineStyle.IsEnabled().value())
	{
		canvas.SetLineWidth(0);
	}
	else
	{
		canvas.SetLineWidth(m_outlineStyle.GetWidth().value());
	}
	
	if (!m_fillStyle.IsEnabled().value())
	{
		canvas.EndFill();
	}
	else
	{
		canvas.BeginFill(m_fillStyle.GetColor().value());
	}

	DoDraw(canvas);

	canvas.EndFill();
}