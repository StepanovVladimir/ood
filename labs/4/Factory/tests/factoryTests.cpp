#include "../../../../catch2/catch.hpp"
#include "../Factory/ShapeFactory.h"
#include "../Factory/Rectangle.h"
#include "../Factory/Triangle.h"
#include "../Factory/Ellipse.h"
#include "../Factory/RegularPolygon.h"
#include "testsUtils.h"

using namespace std;

TEST_CASE("Shape factory invalid arguments tests")
{
	CShapeFactory shapeFactory;

	CHECK_THROWS_AS(shapeFactory.CreateShape(""), invalid_argument);
	CHECK_THROWS_AS(shapeFactory.CreateShape("UnexistentShape"), invalid_argument);
	CHECK_THROWS_AS(shapeFactory.CreateShape("Rectangle"), invalid_argument);
	CHECK_THROWS_AS(shapeFactory.CreateShape("Triangle 2 abc 3 4 5 3 Black"), invalid_argument);
	CHECK_THROWS_AS(shapeFactory.CreateShape("Ellipse 5 6 3 4"), invalid_argument);
	CHECK_THROWS_AS(shapeFactory.CreateShape("RegularPolygon 5.2 6 3 4 Black"), invalid_argument);
	CHECK_THROWS_AS(shapeFactory.CreateShape("Ellipse 5 6 3 4 UnexistentColor"), invalid_argument);
}

TEST_CASE("Shape factory create rectangle tests")
{
	CShapeFactory shapeFactory;
	unique_ptr<CShape> shape = shapeFactory.CreateShape("Rectangle 2 3 4 6 Green");

	CHECK(shape->GetColor() == Color::Green);

	CRectangle* rectangle = dynamic_cast<CRectangle*>(shape.get());

	CHECK(rectangle->GetLeftTop() == Point{ 2, 3 });
	CHECK(rectangle->GetRightBottom() == Point{ 4, 6 });
}

TEST_CASE("Shape factory create triangle tests")
{
	CShapeFactory shapeFactory;
	unique_ptr<CShape> shape = shapeFactory.CreateShape("Triangle 1 2 4 2 3 5 Red");

	CHECK(shape->GetColor() == Color::Red);

	CTriangle* triangle = dynamic_cast<CTriangle*>(shape.get());

	CHECK(triangle->GetVertex1() == Point{ 1, 2 });
	CHECK(triangle->GetVertex2() == Point{ 4, 2 });
	CHECK(triangle->GetVertex3() == Point{ 3, 5 });
}

TEST_CASE("Shape factory create ellipse tests")
{
	CShapeFactory shapeFactory;
	unique_ptr<CShape> shape = shapeFactory.CreateShape("Ellipse 1 2 4 2 3 5 Red");
}