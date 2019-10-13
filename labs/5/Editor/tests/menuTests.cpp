#include "../../../../catch2/catch.hpp"
#include "../Editor/Menu.h"
#include <sstream>

using namespace std;

TEST_CASE("Menu tests")
{
	istringstream inStrm("help\nUnknownCommand\nexit\nhelp");
	ostringstream outStrm;
	CMenu menu(inStrm, outStrm);

	menu.AddItem("help", "Help", [&](istream&) { menu.ShowInstructions(); });
	menu.AddItem("exit", "Exit", [&](istream&) { menu.Exit(); });

	menu.Run();

	istringstream result(outStrm.str());
	string str;

	getline(result, str);
	CHECK(str == "Commands list:");

	getline(result, str);
	CHECK(str == "  help: Help");

	getline(result, str);
	CHECK(str == "  exit: Exit");

	getline(result, str);
	CHECK(str == "Commands list:");

	getline(result, str);
	CHECK(str == "  help: Help");

	getline(result, str);
	CHECK(str == "  exit: Exit");

	getline(result, str);
	CHECK(str == "Unknown command");

	CHECK_FALSE(getline(result, str));
}