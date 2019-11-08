#pragma once

#include "Shape.h"

class CRectangle : public CShape
{
public:
	CRectangle(const RectD& rect, const CLineStyle& outlineStyle, const CStyle& fillStyle);
	
	RectD GetFrame() const override;
	void SetFrame(const RectD& frame) override;

protected:
	void DoDraw(ICanvas& canvas) const override;

private:
	RectD m_rect;
};