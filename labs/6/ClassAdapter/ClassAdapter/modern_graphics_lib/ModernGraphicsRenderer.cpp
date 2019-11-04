#include "ModernGraphicsRenderer.h"

using namespace std;

namespace modern_graphics_lib
{
	CModernGraphicsRenderer::CModernGraphicsRenderer(ostream& strm)
		: m_out(strm)
	{
	}

	CModernGraphicsRenderer::~CModernGraphicsRenderer()
	{
		if (m_drawing)
		{
			EndDraw();
		}
	}

	void CModernGraphicsRenderer::BeginDraw()
	{
		if (m_drawing)
		{
			throw logic_error("Drawing has already begun");
		}
		m_out << "<draw>" << endl;
		m_drawing = true;
	}

	void CModernGraphicsRenderer::DrawLine(const CPoint & start, const CPoint & end, const CRGBAColor& color)
	{
		if (!m_drawing)
		{
			throw logic_error("DrawLine is allowed between BeginDraw()/EndDraw() only");
		}
		m_out << "  <line fromX=\"" << start.x << "\" fromY=\"" << start.y
			<< "\" toX=\"" << end.x << "\" toY=\"" << end.y << "\">\n";
		m_out << "    <color r=\"" << color.r << "\" g=\"" << color.g
			<< "\" b=\"" << color.b << "\" a=\"" << color.a << "\"/>\n";
		m_out << "  </line>\n";
	}

	void CModernGraphicsRenderer::EndDraw()
	{
		if (!m_drawing)
		{
			throw logic_error("Drawing has not been started");
		}
		m_out << "</draw>" << endl;
		m_drawing = false;
	}
}