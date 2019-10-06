#define CATCH_CONFIG_MAIN
#include "../../../../catch2/catch.hpp"
#include "../Factory/Rectangle.h"
#include "../Factory/Triangle.h"
#include "../Factory/Ellipse.h"
#include "../Factory/RegularPolygon.h"
#include "MockCanvas.h"
#include "testsUtils.h"

using namespace std;

TEST_CASE("Rectangle tests")
{
	CHECK_THROWS_AS(CRectangle({ 4, 3 }, { 2, 6 }), invalid_argument);
	CHECK_THROWS_AS(CRectangle({ 2, 6 }, { 4, 3 }), invalid_argument);

	CRectangle rectangle({ 2, 3 }, { 4, 6 }, Color::Blue);

	CHECK(rectangle.GetLeftTop() == Point{ 2, 3 });
	CHECK(rectangle.GetRightBottom() == Point{ 4, 6 });
	CHECK(rectangle.GetColor() == Color::Blue);
}

TEST_CASE("Draw rectangle tests")
{
	CRectangle rectangle({ 2, 3 }, { 4, 6 }, Color::Blue);
	CMockCanvas canvas;
	rectangle.Draw(canvas);
	auto& lines = canvas.GetLines();

	CHECK(canvas.GetEllipses().empty());
	CHECK(lines.size() == 4);

	CHECK(lines[0].from == Point{ 2, 3 });
	CHECK(lines[0].to == Point{ 4, 3 });
	CHECK(lines[0].color == Color::Blue);

	CHECK(lines[1].from == Point{ 4, 3 });
	CHECK(lines[1].to == Point{ 4, 6 });
	CHECK(lines[1].color == Color::Blue);

	CHECK(lines[2].from == Point{ 4, 6 });
	CHECK(lines[2].to == Point{ 2, 6 });
	CHECK(lines[2].color == Color::Blue);

	CHECK(lines[3].from == Point{ 2, 6 });
	CHECK(lines[3].to == Point{ 2, 3 });
	CHECK(lines[3].color == Color::Blue);
}

TEST_CASE("Triangle tests")
{
	CTriangle triangle({ 1, 2 }, { 4, 2 }, { 3, 5 }, Color::Green);

	CHECK(triangle.GetVertex1() == Point{ 1, 2 });
	CHECK(triangle.GetVertex2() == Point{ 4, 2 });
	CHECK(triangle.GetVertex3() == Point{ 3, 5 });
	CHECK(triangle.GetColor() == Color::Green);
}

TEST_CASE("Draw triangle tests")
{
	CTriangle triangle({ 1, 2 }, { 4, 2 }, { 3, 5 }, Color::Green);
	CMockCanvas canvas;
	triangle.Draw(canvas);
	auto& lines = canvas.GetLines();

	CHECK(canvas.GetEllipses().empty());
	CHECK(lines.size() == 3);

	CHECK(lines[0].from == Point{ 1, 2 });
	CHECK(lines[0].to == Point{ 4, 2 });
	CHECK(lines[0].color == Color::Green);

	CHECK(lines[1].from == Point{ 4, 2 });
	CHECK(lines[1].to == Point{ 3, 5 });
	CHECK(lines[1].color == Color::Green);

	CHECK(lines[2].from == Point{ 3, 5 });
	CHECK(lines[2].to == Point{ 1, 2 });
	CHECK(lines[2].color == Color::Green);
}

TEST_CASE("Ellipse tests")
{
	CHECK_THROWS_AS(CEllipse({ 5, 6 }, -3, 2), invalid_argument);
	CHECK_THROWS_AS(CEllipse({ 5, 6 }, 3, -2), invalid_argument);

	CEllipse ellipse({ 5, 6 }, 3, 2, Color::Red);

	CHECK(ellipse.GetCenter() == Point{ 5, 6 });
	CHECK(ellipse.GetHorizontalRadius() == 3);
	CHECK(ellipse.GetVerticalRadius() == 2);
	CHECK(ellipse.GetColor() == Color::Red);
}

TEST_CASE("Draw ellipse tests")
{
	CEllipse ellipse({ 5, 6 }, 3, 2, Color::Red);
	CMockCanvas canvas;
	ellipse.Draw(canvas);
	auto& ellipses = canvas.GetEllipses();

	CHECK(canvas.GetLines().empty());
	CHECK(ellipses.size() == 1);

	CHECK(ellipses[0].center == Point{ 5, 6 });
	CHECK(ellipses[0].horizontalRadius == 3);
	CHECK(ellipses[0].verticalRadius == 2);
	CHECK(ellipses[0].color == Color::Red);
}

TEST_CASE("Regular polygon tests")
{
	CHECK_THROWS_AS(CRegularPolygon(2, { 10, 10 }, 5), invalid_argument);
	CHECK_THROWS_AS(CRegularPolygon(3, { 10, 10 }, -5), invalid_argument);

	CRegularPolygon regularPolygon(4, { 10, 10 }, 5, Color::Yellow);

	CHECK(regularPolygon.GetVerticesCount() == 4);
	CHECK(regularPolygon.GetCenter() == Point{ 10, 10 });
	CHECK(regularPolygon.GetRadius() == 5);
	CHECK(regularPolygon.GetColor() == Color::Yellow);
}

TEST_CASE("Draw regular polygon tests")
{
	CRegularPolygon regularPolygon(4, { 10, 10 }, 5, Color::Yellow);
	CMockCanvas canvas;
	regularPolygon.Draw(canvas);
	auto& lines = canvas.GetLines();

	CHECK(canvas.GetEllipses().empty());
	CHECK(lines.size() == 4);

	CHECK(lines[0].from == Point{ 10, 5 });
	CHECK(lines[0].to == Point{ 15, 10 });
	CHECK(lines[0].color == Color::Yellow);

	CHECK(lines[1].from == Point{ 15, 10 });
	CHECK(lines[1].to == Point{ 10, 15 });
	CHECK(lines[1].color == Color::Yellow);

	CHECK(lines[2].from == Point{ 10, 15 });
	CHECK(lines[2].to == Point{ 5, 10 });
	CHECK(lines[2].color == Color::Yellow);

	CHECK(lines[3].from == Point{ 5, 10 });
	CHECK(lines[3].to == Point{ 10, 5 });
	CHECK(lines[3].color == Color::Yellow);
}