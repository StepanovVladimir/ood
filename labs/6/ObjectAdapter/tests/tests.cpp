#define CATCH_CONFIG_MAIN
#include "../../../../catch2/catch.hpp"
#include "../ObjectAdapter/GraphicsAdapter.h"
#include <sstream>

using namespace std;
using namespace app;
using namespace modern_graphics_lib;

TEST_CASE("Adapter move to and line to tests")
{
	ostringstream outStrm;
	CModernGraphicsRenderer renderer(outStrm);
	CGraphicsAdapter adapter(renderer);

	renderer.BeginDraw();
	adapter.LineTo(10, 15);
	adapter.MoveTo(20, 25);
	adapter.LineTo(30, 35);
	adapter.LineTo(40, 45);
	renderer.EndDraw();

	istringstream result(outStrm.str());
	string str;

	getline(result, str);
	CHECK(str == "<draw>");
	getline(result, str);
	CHECK(str == "  <line fromX=\"0\" fromY=\"0\" toX=\"10\" toY=\"15\"/>");
	getline(result, str);
	CHECK(str == "  <line fromX=\"20\" fromY=\"25\" toX=\"30\" toY=\"35\"/>");
	getline(result, str);
	CHECK(str == "  <line fromX=\"30\" fromY=\"35\" toX=\"40\" toY=\"45\"/>");
	getline(result, str);
	CHECK(str == "</draw>");

	CHECK_FALSE(getline(result, str));
}