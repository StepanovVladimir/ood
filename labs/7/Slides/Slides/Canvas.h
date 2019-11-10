#pragma once

#include "ICanvas.h"
#include <iostream>

class CCanvas : public ICanvas
{
public:
	CCanvas(std::ostream& strm = std::cout);
	~CCanvas();
	void SetLineWidth(double width) override;
	void SetLineColor(RGBAColor color) override;
	void BeginFill(RGBAColor color) override;
	void EndFill() override;
	void MoveTo(double x, double y) override;
	void LineTo(double x, double y) override;
	void DrawEllipse(double left, double top, double width, double height) override;

private:
	std::ostream& m_strm;
	bool m_fillHasBegin;
};