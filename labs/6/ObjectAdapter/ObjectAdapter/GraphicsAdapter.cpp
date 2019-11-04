#include "GraphicsAdapter.h"

using namespace modern_graphics_lib;

namespace app
{
	CGraphicsAdapter::CGraphicsAdapter(CModernGraphicsRenderer& renderer)
		: m_renderer(renderer)
		, m_point(0, 0)
		, m_color(0, 0, 0, 1)
	{
	}

	void CGraphicsAdapter::SetColor(uint32_t argbColor)
	{
		m_color.a = (float)(argbColor & 0xff000000) / (float)0xff000000;
		m_color.r = (float)(argbColor & 0xff0000) / (float)0xff0000;
		m_color.g = (float)(argbColor & 0xff00) / (float)0xff00;
		m_color.b = (float)(argbColor & 0xff) / (float)0xff;
	}

	void CGraphicsAdapter::MoveTo(int x, int y)
	{
		m_point.x = x;
		m_point.y = y;
	}

	void CGraphicsAdapter::LineTo(int x, int y)
	{
		m_renderer.DrawLine(m_point, { x, y }, m_color);
		MoveTo(x, y);
	}
}