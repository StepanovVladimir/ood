#pragma once

#include "Shape.h"

class CTriangle : public CShape
{
public:
	CTriangle(const PointD& p1, const PointD& p2, const PointD& p3,
		const CLineStyle& outlineStyle, const CStyle& fillStyle);

	RectD GetFrame() const override;
	void SetFrame(const RectD& rect) override;

protected:
	void DoDraw(ICanvas& canvas) const override;

private:
	PointD m_p1;
	PointD m_p2;
	PointD m_p3;

	RectD m_frame;

	PointD m_relativeP1;
	PointD m_relativeP2;
	PointD m_relativeP3;
	
	RectD CreateFrame() const;
};