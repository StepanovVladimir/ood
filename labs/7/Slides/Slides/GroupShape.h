#pragma once

#include "Shapes.h"

class CGroupShape : public CShapes, public IShape
{
public:
	CGroupShape();

	RectD GetFrame() const override;
	void SetFrame(const RectD& frame) override;

	const CLineStyle& GetOutlineStyle() const override;
	void SetOutlineStyle(const CLineStyle& outlineStyle) override;

	const CStyle& GetFillStyle() const override;
	void SetFillStyle(const CStyle& fillStyle) override;

	CGroupShape* GetGroup() override;
	const CGroupShape* GetGroup() const override;

	void Draw(ICanvas& canvas) const override;
};