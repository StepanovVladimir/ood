#include "../../../../catch2/catch.hpp"
#include "../Editor/History.h"
#include "../Editor/ChangeStringCommand.h"

using namespace std;

TEST_CASE("History tests")
{
	CHistory history;
	CHECK_FALSE(history.CanUndo());
	CHECK_FALSE(history.CanRedo());

	string str;

	history.AddAndExecuteCommand(make_unique<CChangeStringCommand>(str, "first"));

	CHECK(str == "first");
	CHECK(history.CanUndo());
	CHECK_FALSE(history.CanRedo());

	history.Undo();

	CHECK(str == "");
	CHECK_FALSE(history.CanUndo());
	CHECK(history.CanRedo());

	history.Redo();

	CHECK(str == "first");
	CHECK(history.CanUndo());
	CHECK_FALSE(history.CanRedo());

	history.Undo();
	history.AddAndExecuteCommand(make_unique<CChangeStringCommand>(str, "second"));

	CHECK(str == "second");
	CHECK(history.CanUndo());
	CHECK_FALSE(history.CanRedo());

	history.Undo();

	CHECK(str == "");
	CHECK_FALSE(history.CanUndo());
	CHECK(history.CanRedo());
}

TEST_CASE("10 commands tests")
{
	CHistory history;
	string str;

	history.AddAndExecuteCommand(make_unique<CChangeStringCommand>(str, "1"));
	history.AddAndExecuteCommand(make_unique<CChangeStringCommand>(str, "2"));
	history.AddAndExecuteCommand(make_unique<CChangeStringCommand>(str, "3"));
	history.AddAndExecuteCommand(make_unique<CChangeStringCommand>(str, "4"));
	history.AddAndExecuteCommand(make_unique<CChangeStringCommand>(str, "5"));
	history.AddAndExecuteCommand(make_unique<CChangeStringCommand>(str, "6"));
	history.AddAndExecuteCommand(make_unique<CChangeStringCommand>(str, "7"));
	history.AddAndExecuteCommand(make_unique<CChangeStringCommand>(str, "8"));
	history.AddAndExecuteCommand(make_unique<CChangeStringCommand>(str, "9"));
	history.AddAndExecuteCommand(make_unique<CChangeStringCommand>(str, "10"));
	history.AddAndExecuteCommand(make_unique<CChangeStringCommand>(str, "11"));

	history.Undo();
	history.Undo();
	history.Undo();
	history.Undo();
	history.Undo();
	history.Undo();
	history.Undo();
	history.Undo();
	history.Undo();

	CHECK(history.CanUndo());

	history.Undo();

	CHECK_FALSE(history.CanUndo());
	CHECK(str == "1");
}