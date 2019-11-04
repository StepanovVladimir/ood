#include "GraphicsAdapter.h"

using namespace modern_graphics_lib;

namespace app
{
	CGraphicsAdapter::CGraphicsAdapter(CModernGraphicsRenderer& renderer)
		: m_renderer(renderer)
		, m_point(0, 0)
	{
	}

	void CGraphicsAdapter::MoveTo(int x, int y)
	{
		m_point.x = x;
		m_point.y = y;
	}

	void CGraphicsAdapter::LineTo(int x, int y)
	{
		m_renderer.DrawLine(m_point, { x, y });
		MoveTo(x, y);
	}
}