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
	cout << "SetLineColor (#" << strm.str() << ')' << endl;
}

void CCanvas::BeginFill(RGBAColor color)
{
	EndFill();

	ostringstream strm;
	strm << setfill('0') << setw(8) << hex << color;
	cout << "BeginFill (#" << strm.str() << ')' << endl;
}

void CCanvas::EndFill()
{
	if (m_fillHasBegin)
	{
		cout << "EndFill" << endl;
	}
}

void CCanvas::MoveTo(double x, double y)
{
	cout << "MoveTo (" << x << ", " << y << ")" << endl;
}

void CCanvas::LineTo(double x, double y)
{
	cout << "LineTo (" << x << ", " << y << ")" << endl;
}

void CCanvas::DrawEllipse(double left, double top, double width, double height)
{
	cout << "DrawEllipse (" << left << ", " << top << ", " << width << ", " << height << ")" << endl;
}