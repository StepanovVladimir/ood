#define CATCH_CONFIG_MAIN
#include "../../../../catch2/catch.hpp"
#include "../Editor/ChangeStringCommand.h"

using namespace std;

TEST_CASE("Change string command tests")
{
	string str = "first";
	CChangeStringCommand command(str, "second");
	CHECK(str == "first");

	command.Unexecute();
	CHECK(str == "first");

	command.Execute();
	CHECK(str == "second");

	command.Execute();
	CHECK(str == "second");

	command.Unexecute();
	CHECK(str == "first");
}