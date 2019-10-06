#include "pch.h"
#include "ShapeFactory.h"
#include "Designer.h"
#include "Canvas.h"
#include "Painter.h"
#include <iostream>

using namespace std;

int main()
{
	CShapeFactory shapeFactory;
	CDesigner designer(shapeFactory);
	CPictureDraft pictureDraft = designer.CreateDraft(cin);
	CCanvas canvas;
	CPainter painter;
	painter.DrawPicture(pictureDraft, canvas);
}