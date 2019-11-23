#pragma once

#include "Shape.h"

class CEllipse : public CShape
{
public:
	CEllipse(const RectD& ellipse, const CLineStyle& outlineStyle, const CStyle& fillStyle);

	std::optional<RectD> GetFrame() const override;
	void SetFrame(const RectD& frame) override;

protected:
	void DoDraw(ICanvas& canvas) const override;

private:
	RectD m_ellipse;
};