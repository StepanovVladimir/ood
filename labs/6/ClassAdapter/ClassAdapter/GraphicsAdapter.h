#pragma once

#include "graphics_lib/ICanvas.h"
#include "modern_graphics_lib/ModernGraphicsRenderer.h"

namespace app
{
	class CGraphicsAdapter
		: public modern_graphics_lib::CModernGraphicsRenderer
		, public graphics_lib::ICanvas
	{
	public:
		CGraphicsAdapter(std::ostream& strm);

		void SetColor(uint32_t argbColor) override;
		void MoveTo(int x, int y) override;
		void LineTo(int x, int y) override;

	private:
		modern_graphics_lib::CPoint m_point;
		modern_graphics_lib::CRGBAColor m_color;
	};
}