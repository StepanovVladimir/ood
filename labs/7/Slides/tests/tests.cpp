#define CATCH_CONFIG_MAIN
#include "../../../../catch2/catch.hpp"
#include "../Slides/GroupShape.h"
#include "../Slides/Rectangle.h"
#include "../Slides/Ellipse.h"
#include "../Slides/Canvas.h"
#include "../Slides/ConstShapes.h"
#include <sstream>

using namespace std;

TEST_CASE("Exception in constructor on group of less than two elements")
{
	vector<shared_ptr<IShape>> shapes;
	shapes.push_back(make_shared<CRectangle>(RectD({ 2, 3 }, 4, 5), CLineStyle(true), CStyle(true, 0xaa3399dd)));

	CHECK_THROWS_AS(CGroupShape(shapes), runtime_error);
}

TEST_CASE("Сonstructor group shape")
{
	vector<shared_ptr<IShape>> shapes;
	shared_ptr<IShape> rectangle = make_shared<CRectangle>(RectD({ 2, 3 }, 4, 5), CLineStyle(true), CStyle(true, 0xaa3399dd));
	shared_ptr<IShape> ellipse = make_shared<CEllipse>(RectD({ 10, 14 }, 6, 7), CLineStyle(true, 0x001122ff, 2), CStyle(false));
	shapes.push_back(rectangle);
	shapes.push_back(ellipse);

	CGroupShape group(shapes);

	CHECK(group.GetOutlineStyle() == CLineStyle());
	CHECK(group.GetFillStyle() == CStyle());
	CHECK(group.GetGroup() == &group);

	CConstShapes groupShapes = group.GetShapes();

	CHECK(groupShapes.GetShapesCount() == 2);
	CHECK(groupShapes[0] == rectangle);
	CHECK(groupShapes[1] == ellipse);
}

TEST_CASE("Set outline style on group shape")
{
	vector<shared_ptr<IShape>> shapes;
	shared_ptr<IShape> rectangle = make_shared<CRectangle>(RectD({ 2, 3 }, 4, 5), CLineStyle(true), CStyle(true, 0xaa3399dd));
	shared_ptr<IShape> ellipse = make_shared<CEllipse>(RectD({ 10, 14 }, 6, 7), CLineStyle(true, 0x001122ff, 2), CStyle(false));
	shapes.push_back(rectangle);
	shapes.push_back(ellipse);
	CGroupShape group(shapes);
	CLineStyle outlineStyle(true, 0x112233aa, 3);

	group.SetOutlineStyle(outlineStyle);

	CHECK(rectangle->GetOutlineStyle() == outlineStyle);
	CHECK(ellipse->GetOutlineStyle() == outlineStyle);

	CHECK(group.GetOutlineStyle() == outlineStyle);
}

TEST_CASE("Set fill style on group shape")
{
	vector<shared_ptr<IShape>> shapes;
	shared_ptr<IShape> rectangle = make_shared<CRectangle>(RectD({ 2, 3 }, 4, 5), CLineStyle(true), CStyle(true, 0xaa3399dd));
	shared_ptr<IShape> ellipse = make_shared<CEllipse>(RectD({ 10, 14 }, 6, 7), CLineStyle(true, 0x001122ff, 2), CStyle(false));
	shapes.push_back(rectangle);
	shapes.push_back(ellipse);
	CGroupShape group(shapes);
	CStyle fillStyle(true, 0x112233aa);

	group.SetFillStyle(fillStyle);

	CHECK(rectangle->GetFillStyle() == fillStyle);
	CHECK(ellipse->GetFillStyle() == fillStyle);

	CHECK(group.GetFillStyle() == fillStyle);
}

TEST_CASE("Draw group shape")
{
	vector<shared_ptr<IShape>> shapes;
	shared_ptr<IShape> rectangle = make_shared<CRectangle>(RectD({ 2, 3 }, 4, 5), CLineStyle(true), CStyle(true, 0xaa3399dd));
	shared_ptr<IShape> ellipse = make_shared<CEllipse>(RectD({ 10, 14 }, 6, 7), CLineStyle(true, 0x001122ff, 2), CStyle(false));
	shapes.push_back(rectangle);
	shapes.push_back(ellipse);
	CGroupShape group(shapes);

	ostringstream outStrm;
	CCanvas canvas(outStrm);

	group.Draw(canvas);

	istringstream result(outStrm.str());
	string str;

	getline(result, str);
	CHECK(str == "SetLineColor (#000000ff)");
	getline(result, str);
	CHECK(str == "SetLineWidth (1)");
	getline(result, str);
	CHECK(str == "BeginFill (#aa3399dd)");
	getline(result, str);
	CHECK(str == "MoveTo (2, 3)");
	getline(result, str);
	CHECK(str == "LineTo (6, 3)");
	getline(result, str);
	CHECK(str == "LineTo (6, 8)");
	getline(result, str);
	CHECK(str == "LineTo (2, 8)");
	getline(result, str);
	CHECK(str == "LineTo (2, 3)");
	getline(result, str);
	CHECK(str == "EndFill");

	getline(result, str);
	CHECK(str == "SetLineColor (#001122ff)");
	getline(result, str);
	CHECK(str == "SetLineWidth (2)");
	getline(result, str);
	CHECK(str == "DrawEllipse (10, 14, 6, 7)");

	CHECK_FALSE(getline(result, str));
}

template<typename T>
bool operator==(const Rect<T> &rect1, const Rect<T> &rect2)
{
	return rect1.GetLeftTop().x == rect2.GetLeftTop().x && rect1.GetLeftTop().y == rect2.GetLeftTop().y
		&& rect1.GetWidth() == rect2.GetWidth() && rect1.GetHeight() == rect2.GetHeight();
}

TEST_CASE("Get frame from group shape")
{
	vector<shared_ptr<IShape>> shapes;
	shared_ptr<IShape> rectangle = make_shared<CRectangle>(RectD({ 2, 4 }, 4, 2), CLineStyle(true), CStyle(true));
	shared_ptr<IShape> ellipse = make_shared<CEllipse>(RectD({ 8, 0 }, 4, 8), CLineStyle(true), CStyle(true));
	shapes.push_back(rectangle);
	shapes.push_back(ellipse);
	CGroupShape group(shapes);

	CHECK(group.GetFrame() == RectD({ 2, 0 }, 10, 8));
}

TEST_CASE("Set frame to group shape")
{
	vector<shared_ptr<IShape>> shapes;
	shared_ptr<IShape> rectangle = make_shared<CRectangle>(RectD({ 2, 4 }, 4, 2), CLineStyle(true), CStyle(true));
	shared_ptr<IShape> ellipse = make_shared<CEllipse>(RectD({ 8, 0 }, 4, 8), CLineStyle(true), CStyle(true));
	shapes.push_back(rectangle);
	shapes.push_back(ellipse);
	CGroupShape group(shapes);

	group.SetFrame(RectD({ 4, 10 }, 5, 4));
	
	CHECK(rectangle->GetFrame() == RectD({ 4, 12 }, 2, 1));
	CHECK(ellipse->GetFrame() == RectD({ 7, 10 }, 2, 4));

	CHECK(group.GetFrame() == RectD({ 4, 10 }, 5, 4));
}