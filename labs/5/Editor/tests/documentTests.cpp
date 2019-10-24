#include "../../../../catch2/catch.hpp"
#include "../Editor/Document.h"
#include <fstream>
#include <filesystem>

using namespace std;

TEST_CASE("Document set title tests")
{
	CDocument document;
	
	CHECK(document.GetItemsCount() == 0);
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
	CHECK(document.GetItem(0).GetParagraph()->GetText() == "first");

	document.InsertParagraph("second", 0);

	CHECK(document.GetItemsCount() == 2);
	CHECK(document.GetItem(0).GetParagraph()->GetText() == "second");
	CHECK(document.GetItem(1).GetParagraph()->GetText() == "first");
}

TEST_CASE("Document insert image tests")
{
	CDocument document;
	document.InsertImage("TestResources/fox.jpg", 200, 150);

	CHECK(document.GetItemsCount() == 1);
	CHECK(document.GetItem(0).GetImage()->GetPath() == "4.jpg");
	CHECK(document.GetItem(0).GetImage()->GetWidth() == 200);
	CHECK(document.GetItem(0).GetImage()->GetHeight() == 150);
}

TEST_CASE("Document replace text of paragraph tests")
{
	CDocument document;
	document.InsertParagraph("first");

	CHECK_THROWS_AS(document.ReplaceText("second", 1), runtime_error);

	document.ReplaceText("second", 0);
	CHECK(document.GetItem(0).GetParagraph()->GetText() == "second");
}

TEST_CASE("Document resize image tests")
{
	CDocument document;
	document.InsertParagraph("first");
	document.InsertImage("TestResources/fox.jpg", 200, 150);

	CHECK_THROWS_AS(document.ResizeImage(300, 200, 0), runtime_error);

	document.ResizeImage(300, 200, 1);
	CHECK(document.GetItem(1).GetImage()->GetWidth() == 300);
	CHECK(document.GetItem(1).GetImage()->GetHeight() == 200);
}

TEST_CASE("Document delete item tests")
{
	CDocument document;
	document.InsertParagraph("first");

	document.DeleteItem(0);

	CHECK(document.GetItemsCount() == 0);
}

TEST_CASE("Document save tests")
{
	CDocument document;
	document.SetTitle("<title>");
	document.InsertParagraph("\"first\"");
	document.InsertParagraph("&'second'");
	document.InsertImage("TestResources/fox.jpg", 200, 150);

	CHECK_THROWS_AS(document.Save("nonexistentFolder"), runtime_error);

	filesystem::create_directory("TestResults");
	document.Save("TestResults");

	CHECK(filesystem::exists("TestResults/images/6.jpg"));

	ifstream fIn("TestResults/index.html");
	string str;

	getline(fIn, str);
	CHECK("<!DOCTYPE html>");
	getline(fIn, str);
	CHECK("<html>");
	getline(fIn, str);
	CHECK("  <head>");
	getline(fIn, str);
	CHECK("    <title>&lt;title&gt;</title>");
	getline(fIn, str);
	CHECK("  </head>");
	getline(fIn, str);
	CHECK("  <body>");
	getline(fIn, str);
	CHECK("    <h1>&lt;title&gt;</h1>");
	getline(fIn, str);
	CHECK("    <p>&quot;first&quot;</p>");
	getline(fIn, str);
	CHECK("    <p>&amp;&apos;second&apos;</p>");
	getline(fIn, str);
	CHECK("    <img src=\"images/6.jpg\" width=\"200\" height=\"150\">");
	getline(fIn, str);
	CHECK("  </body>");
	getline(fIn, str);
	CHECK("</html>");

	CHECK_FALSE(getline(fIn, str));
}