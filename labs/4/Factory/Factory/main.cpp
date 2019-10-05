#include "pch.h"
#include "Canvas.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Ellipse.h"
#include "RegularPolygon.h"
#include <iostream>

using namespace std;

int main()
{
	CCanvas canvas;
	
	CRectangle rectangle(Point{ 2, 3 }, Point{ 4, 6 });
	CTriangle triangle(Point{ 1, 2 }, Point{ 4, 2 }, Point{ 2, 7 }, Color::Pink);
	CEllipse ellipse(Point{ 5, 5 }, 6, 3);
	CRegularPolygon regularPolygon(4, Point{ 10, 10 }, 5);

	rectangle.Draw(canvas);
	cout << "-----------------------\n";
	triangle.Draw(canvas);
	cout << "-----------------------\n";
	ellipse.Draw(canvas);
	cout << "-----------------------\n";
	regularPolygon.Draw(canvas);
}