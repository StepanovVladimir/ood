#include "pch.h"
#include "ShapeFactory.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Ellipse.h"
#include "RegularPolygon.h"
#include <sstream>

using namespace std;

unique_ptr<CShape> CShapeFactory::CreateShape(const string& description) const
{
	istringstream strm(description);
	string shapeType;

	if (!(strm >> shapeType))
	{
		throw invalid_argument("Description is empty");
	}

	if (shapeType == "Rectangle")
	{
		return CreateRectangle(strm);
	}
	if (shapeType == "Triangle")
	{
		return CreateTriangle(strm);
	}
	if (shapeType == "Ellipse")
	{
		return CreateEllipse(strm);
	}
	if (shapeType == "RegularPolygon")
	{
		return CreateRegularPolygon(strm);
	}
	throw invalid_argument("Unknown shape type");
}

unique_ptr<CShape> CShapeFactory::CreateRectangle(istream& strm) const
{
	Point leftTop;
	Point rightBottom;
	string color;
	strm >> leftTop.x >> leftTop.y >> rightBottom.x >> rightBottom.y >> color;

	if (!strm)
	{
		throw invalid_argument("Invalid arguments to create a rectangle");
	}

	return make_unique<CRectangle>(leftTop, rightBottom, StringToColor(color));
}

unique_ptr<CShape> CShapeFactory::CreateTriangle(istream& strm) const
{
	Point vertex1;
	Point vertex2;
	Point vertex3;
	string color;
	strm >> vertex1.x >> vertex1.y >> vertex2.x >> vertex2.y >> vertex3.x >> vertex3.y >> color;

	if (!strm)
	{
		throw invalid_argument("Invalid arguments to create a triangle");
	}

	return make_unique<CTriangle>(vertex1, vertex2, vertex3, StringToColor(color));
}

unique_ptr<CShape> CShapeFactory::CreateEllipse(istream& strm) const
{
	Point center;
	double horizontalRadius;
	double verticalRadius;
	string color;
	strm >> center.x >> center.y >> horizontalRadius >> verticalRadius >> color;

	if (!strm)
	{
		throw invalid_argument("Invalid arguments to create a ellipse");
	}

	return make_unique<CEllipse>(center, horizontalRadius, verticalRadius, StringToColor(color));
}

unique_ptr<CShape> CShapeFactory::CreateRegularPolygon(istream& strm) const
{
	short verticesCount;
	Point center;
	double radius;
	string color;
	strm >> verticesCount >> center.x >> center.y >> radius >> color;

	if (!strm || verticesCount > 100)
	{
		throw invalid_argument("Invalid arguments to create a regular polygon");
	}

	return make_unique<CRegularPolygon>((int8_t)verticesCount, center, radius, StringToColor(color));
}

Color CShapeFactory::StringToColor(const std::string& str) const
{
	if (str == "Green")
	{
		return Color::Green;
	}
	if (str == "Red")
	{
		return Color::Red;
	}
	if (str == "Blue")
	{
		return Color::Blue;
	}
	if (str == "Yellow")
	{
		return Color::Yellow;
	}
	if (str == "Pink")
	{
		return Color::Pink;
	}
	if (str == "Black")
	{
		return Color::Black;
	}
	throw invalid_argument("Unknown color");
}