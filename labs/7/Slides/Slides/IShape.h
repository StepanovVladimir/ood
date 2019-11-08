#pragma once

#include "IDrawable.h"
#include "LineStyle.h"

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

	virtual CGroupShape* GetGroup() = 0;
	virtual const CGroupShape* GetGroup() const = 0;
};