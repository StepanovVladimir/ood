#pragma once

#include "graphics_lib/ICanvas.h"
#include "modern_graphics_lib/ModernGraphicsRenderer.h"

namespace app
{
	class CGraphicsAdapter : public graphics_lib::ICanvas
	{
	public:
		CGraphicsAdapter(modern_graphics_lib::CModernGraphicsRenderer& renderer);

		void MoveTo(int x, int y) override;
		void LineTo(int x, int y) override;

	private:
		modern_graphics_lib::CModernGraphicsRenderer& m_renderer;
		modern_graphics_lib::CPoint m_point;
	};
}