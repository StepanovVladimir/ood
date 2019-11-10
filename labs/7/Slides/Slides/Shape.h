#pragma once

#include "IShape.h"

class CShape : public IShape
{
public:
	CShape(const CLineStyle& outlineStyle, const CStyle& fillStyle);

	const CLineStyle& GetOutlineStyle() const override;
	void SetOutlineStyle(const CLineStyle& outlineStyle) override;

	const CStyle& GetFillStyle() const override;
	void SetFillStyle(const CStyle& fillStyle) override;

	std::shared_ptr<CGroupShape> GetGroup() override;
	const std::shared_ptr<CGroupShape> GetGroup() const override;

	void Draw(ICanvas& canvas) const override;

protected:
	virtual void DoDraw(ICanvas& canvas) const = 0;

private:
	CLineStyle m_outlineStyle;
	CStyle m_fillStyle;
};