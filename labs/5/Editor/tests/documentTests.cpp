#include "../../../../catch2/catch.hpp"
#include "../Editor/Document.h"

using namespace std;

TEST_CASE("Document tests")
{
	CDocument document;
	
	CHECK(document.GetTitle() == "");
	CHECK_FALSE(document.CanUndo());
	CHECK_FALSE(document.CanRedo());

	document.SetTitle("first");

	CHECK(document.GetTitle() == "first");
	CHECK(document.CanUndo());
	CHECK_FALSE(document.CanRedo());

	document.Undo();

	CHECK(document.GetTitle() == "");
	CHECK_FALSE(document.CanUndo());
	CHECK(document.CanRedo());

	document.Redo();

	CHECK(document.GetTitle() == "first");
	CHECK(document.CanUndo());
	CHECK_FALSE(document.CanRedo());
}