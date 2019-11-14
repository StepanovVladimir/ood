#include "pch.h"
#include "Canvas.h"
#include <sstream>
#include <iomanip>

using namespace std;

CCanvas::CCanvas(ostream& strm)
	: m_strm(strm)
	, m_fillHasBegin(false)
{
}

CCanvas::~CCanvas()
{
	EndFill();
}

void CCanvas::SetLineWidth(double width)
{
	m_strm << "SetLineWidth (" << width << ")" << endl;
}

void CCanvas::SetLineColor(RGBAColor color)
{
	ostringstream strm;
	strm << setfill('0') << setw(8) << hex << color;
	m_strm << "SetLineColor (#" << strm.str() << ')' << endl;
}

void CCanvas::BeginFill(RGBAColor color)
{
	EndFill();

	ostringstream strm;
	strm << setfill('0') << setw(8) << hex << color;
	m_strm << "BeginFill (#" << strm.str() << ')' << endl;
	m_fillHasBegin = true;
}

void CCanvas::EndFill()
{
	if (m_fillHasBegin)
	{
		m_strm << "EndFill" << endl;
		m_fillHasBegin = false;
	}
}

void CCanvas::MoveTo(double x, double y)
{
	m_strm << "MoveTo (" << x << ", " << y << ")" << endl;
}

void CCanvas::LineTo(double x, double y)
{
	m_strm << "LineTo (" << x << ", " << y << ")" << endl;
}

void CCanvas::DrawEllipse(double left, double top, double width, double height)
{
	m_strm << "DrawEllipse (" << left << ", " << top << ", " << width << ", " << height << ")" << endl;
}