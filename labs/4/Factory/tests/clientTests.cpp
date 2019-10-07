#include "../../../../catch2/catch.hpp"
#include "../Factory/Client.h"
#include "MockCanvas.h"
#include "testsUtils.h"
#include <sstream>

using namespace std;

TEST_CASE("Client tests")
{
	istringstream strm("Triangle 1 2 4 2 3 5 Green\nEllipse 5 6 3 2 Red\n");
	CMockCanvas canvas;

	CClient client;

	CHECK_THROWS_AS(client.DrawPicture(canvas), runtime_error);

	client.CreatePictureDraft(strm);
	client.DrawPicture(canvas);

	auto& lines = canvas.GetLines();
	auto& ellipses = canvas.GetEllipses();

	CHECK(lines.size() == 3);
	CHECK(ellipses.size() == 1);

	SECTION("Check triangle")
	{
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

	SECTION("Check ellipse")
	{
		CHECK(ellipses[0].leftTop == Point{ 2, 4 });
		CHECK(ellipses[0].width == 6);
		CHECK(ellipses[0].height == 4);
		CHECK(ellipses[0].color == Color::Red);
	}
}