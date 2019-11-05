#pragma once

#include "Point.h"
#include "RGBAColor.h"
#include <iostream>

namespace modern_graphics_lib
{
	class CModernGraphicsRenderer
	{
	public:
		CModernGraphicsRenderer(std::ostream& strm);
		virtual ~CModernGraphicsRenderer();

		void BeginDraw();
		void DrawLine(const CPoint& start, const CPoint& end, const CRGBAColor& color);
		void EndDraw();

	private:
		std::ostream& m_out;
		bool m_drawing = false;
	};
}