#pragma once

#include "ICanvasDrawable.h"
#include "Point.h"

namespace shape_drawing_lib
{
	class CRectangle : public ICanvasDrawable
	{
	public:
		CRectangle(const Point& leftTop, int width, int height);

		void Draw(graphics_lib::ICanvas& canvas) const override;

	private:

	};
}