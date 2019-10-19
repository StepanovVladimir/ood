#include "../../../../catch2/catch.hpp"
#include "../Editor/Document.h"
#include <fstream>

using namespace std;

TEST_CASE("Document set title tests")
{
	CDocument document;
	
	CHECK(document.GetItemsCount() == 0);
	CHECK(document.begin() == document.end());
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

TEST_CASE("Document insert paragraph tests")
{
	CDocument document;
	document.InsertParagraph("first");

	CHECK(document.GetItemsCount() == 1);
	CHECK(document.begin()->GetParagraph()->GetText() == "first");

	document.InsertParagraph("second", 0);

	CHECK(document.GetItemsCount() == 2);
	CHECK(document.begin()->GetParagraph()->GetText() == "second");
	CHECK((++document.begin())->GetParagraph()->GetText() == "first");
}

TEST_CASE("Document replace text of paragraph tests")
{
	CDocument document;
	document.InsertParagraph("first");

	document.ReplaceText("second", 0);

	CHECK(document.begin()->GetParagraph()->GetText() == "second");
}

TEST_CASE("Document delete item tests")
{
	CDocument document;
	document.InsertParagraph("first");

	document.DeleteItem(0);

	CHECK(document.GetItemsCount() == 0);
	CHECK(document.begin() == document.end());
}

TEST_CASE("Document save tests")
{
	CDocument document;
	document.SetTitle("title");
	document.InsertParagraph("first");
	document.InsertParagraph("second");
	document.Save("index");

	ifstream fOut("index.html");
	string str;

	getline(fOut, str);
	CHECK("<!DOCTYPE html>");
	getline(fOut, str);
	CHECK("<html>");
	getline(fOut, str);
	CHECK("  <head>");
	getline(fOut, str);
	CHECK("    <title>title</title>");
	getline(fOut, str);
	CHECK("  </head>");
	getline(fOut, str);
	CHECK("  <body>");
	getline(fOut, str);
	CHECK("    <h1>title</h1>");
	getline(fOut, str);
	CHECK("    <p>first</p>");
	getline(fOut, str);
	CHECK("    <p>second</p>");
	getline(fOut, str);
	CHECK("  </body>");
	getline(fOut, str);
	CHECK("</html>");

	CHECK_FALSE(getline(fOut, str));
}