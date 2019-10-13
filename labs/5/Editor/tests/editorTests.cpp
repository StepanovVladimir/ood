#include "../../../../catch2/catch.hpp"
#include "../Editor/Editor.h"
#include <sstream>

using namespace std;

TEST_CASE("Editor tests")
{
	istringstream inStrm("list\nundo\nredo\nexit");
	ostringstream outStrm;
	CEditor editor(inStrm, outStrm);

	editor.Start();

	istringstream result(outStrm.str());
	string str;

	getline(result, str);
	CHECK(str == "Commands list:");
	getline(result, str);
	CHECK(str == "  help: Help");
	getline(result, str);
	CHECK(str == "  exit: Exit");
	getline(result, str);
	CHECK(str == "  setTitle: Changes title. Args: <new title>");
	getline(result, str);
	CHECK(str == "  list: Show document");
	getline(result, str);
	CHECK(str == "  undo: Undo command");
	getline(result, str);
	CHECK(str == "  redo: Redo undone command");

	getline(result, str);
	CHECK(str == "-------------");
	getline(result, str);
	CHECK(str == "");
	getline(result, str);
	CHECK(str == "-------------");

	getline(result, str);
	CHECK(str == "Can't undo");

	getline(result, str);
	CHECK(str == "Can't redo");

	CHECK_FALSE(getline(result, str));
}

TEST_CASE("Editor set title tests")
{
	istringstream inStrm("setTitle word1 word2\nlist\nundo\nlist\nredo\nlist\nexit");
	ostringstream outStrm;
	CEditor editor(inStrm, outStrm);

	editor.Start();

	istringstream result(outStrm.str());
	string str;

	getline(result, str);
	getline(result, str);
	getline(result, str);
	getline(result, str);
	getline(result, str);
	getline(result, str);
	getline(result, str);

	getline(result, str);
	CHECK(str == "-------------");
	getline(result, str);
	CHECK(str == "word1 word2");
	getline(result, str);
	CHECK(str == "-------------");

	getline(result, str);
	CHECK(str == "-------------");
	getline(result, str);
	CHECK(str == "");
	getline(result, str);
	CHECK(str == "-------------");

	getline(result, str);
	CHECK(str == "-------------");
	getline(result, str);
	CHECK(str == "word1 word2");
	getline(result, str);
	CHECK(str == "-------------");

	CHECK_FALSE(getline(result, str));
}