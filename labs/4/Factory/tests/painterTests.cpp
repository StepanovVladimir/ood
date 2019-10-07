#include "../../../../catch2/catch.hpp"
#include "../Factory/Painter.h"
#include "../Factory/PictureDraft.h"
#include "../Factory/Rectangle.h"
#include "../Factory/Triangle.h"
#include "../Factory/Ellipse.h"
#include "../Factory/RegularPolygon.h"
#include "MockCanvas.h"
#include "testsUtils.h"

using namespace std;

TEST_CASE("Painter tests")
{
	CPictureDraft pictureDraft;
	pictureDraft.AddShape(make_unique<CRectangle>(Point{ 2, 3 }, Point{ 4, 6 }, Color::Blue));
	pictureDraft.AddShape(make_unique<CTriangle>(Point{ 1, 2 }, Point{ 4, 2 }, Point{ 3, 5 }, Color::Green));
	pictureDraft.AddShape(make_unique<CEllipse>(Point{ 5, 6 }, 3, 2, Color::Red));
	pictureDraft.AddShape(make_unique<CRegularPolygon>(4, Point{ 10, 10 }, 5, Color::Yellow));

	CMockCanvas canvas;

	CPainter painter;
	painter.DrawPicture(pictureDraft, canvas);

	auto& lines = canvas.GetLines();
	auto& ellipses = canvas.GetEllipses();

	CHECK(lines.size() == 11);
	CHECK(ellipses.size() == 1);

	SECTION("Check rectangle")
	{
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

	SECTION("Check triangle")
	{
		CHECK(lines[4].from == Point{ 1, 2 });
		CHECK(lines[4].to == Point{ 4, 2 });
		CHECK(lines[4].color == Color::Green);

		CHECK(lines[5].from == Point{ 4, 2 });
		CHECK(lines[5].to == Point{ 3, 5 });
		CHECK(lines[5].color == Color::Green);

		CHECK(lines[6].from == Point{ 3, 5 });
		CHECK(lines[6].to == Point{ 1, 2 });
		CHECK(lines[6].color == Color::Green);
	}
	
	SECTION("Check ellipse")
	{
		CHECK(ellipses[0].leftTop == Point{ 2, 4 });
		CHECK(ellipses[0].width == 6);
		CHECK(ellipses[0].height == 4);
		CHECK(ellipses[0].color == Color::Red);
	}

	SECTION("Check regular polygon")
	{
		CHECK(lines[7].from == Point{ 10, 5 });
		CHECK(lines[7].to == Point{ 15, 10 });
		CHECK(lines[7].color == Color::Yellow);

		CHECK(lines[8].from == Point{ 15, 10 });
		CHECK(lines[8].to == Point{ 10, 15 });
		CHECK(lines[8].color == Color::Yellow);

		CHECK(lines[9].from == Point{ 10, 15 });
		CHECK(lines[9].to == Point{ 5, 10 });
		CHECK(lines[9].color == Color::Yellow);

		CHECK(lines[10].from == Point{ 5, 10 });
		CHECK(lines[10].to == Point{ 10, 5 });
		CHECK(lines[10].color == Color::Yellow);
	}
}