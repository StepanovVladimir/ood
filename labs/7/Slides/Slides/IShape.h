#pragma once

#include "IDrawable.h"
#include "LineStyle.h"
#include <memory>

class CGroupShape;

class IShape : public IDrawable
{
public:
	virtual RectD GetFrame() const = 0;
	virtual void SetFrame(const RectD& frame) = 0;

	virtual const CLineStyle& GetOutlineStyle() const = 0;
	virtual void SetOutlineStyle(const CLineStyle& outlineStyle) = 0;

	virtual const CStyle& GetFillStyle() const = 0;
	virtual void SetFillStyle(const CStyle& fillStyle) = 0;

	virtual std::shared_ptr<CGroupShape> GetGroup() = 0;
	virtual const std::shared_ptr<CGroupShape> GetGroup() const = 0;
};