#pragma once

#include "ICanvas.h"

class CShape
{
public:
	virtual ~CShape() = default;

	virtual void Draw(ICanvas& canvas) const = 0;

	Color GetColor() const;
protected:
	CShape(Color color);

private:
	Color m_color;
};