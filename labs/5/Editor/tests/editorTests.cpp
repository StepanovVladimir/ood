#include "../../../../catch2/catch.hpp"
#include "../Editor/Editor.h"
#include <sstream>
#include <fstream>

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
	CHECK(str == "  insertParagraph: Inserts paragraph. Args: <position>|end <text>");
	getline(result, str);
	CHECK(str == "  insertImage: Inserts image. Args: <position>|end <width> <height> <path>");
	getline(result, str);
	CHECK(str == "  setTitle: Changes title. Args: <title>");
	getline(result, str);
	CHECK(str == "  list: Show document");
	getline(result, str);
	CHECK(str == "  replaceText: Replaces text of paragraph. Args: <position> <text>");
	getline(result, str);
	CHECK(str == "  resizeImage: Resizes image. Args: <position> <width> <height>");
	getline(result, str);
	CHECK(str == "  deleteItem: Deletes document item. Args: <position>");
	getline(result, str);
	CHECK(str == "  undo: Undo command");
	getline(result, str);
	CHECK(str == "  redo: Redo undone command");
	getline(result, str);
	CHECK(str == "  save: Saves document. Args: <path>");

	getline(result, str);
	CHECK(str == "-------------");
	getline(result, str);
	CHECK(str == "Title: ");
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
	getline(result, str);
	getline(result, str);
	getline(result, str);
	getline(result, str);
	getline(result, str);

	getline(result, str);
	CHECK(str == "-------------");
	getline(result, str);
	CHECK(str == "Title: word1 word2");
	getline(result, str);
	CHECK(str == "-------------");

	getline(result, str);
	CHECK(str == "-------------");
	getline(result, str);
	CHECK(str == "Title: ");
	getline(result, str);
	CHECK(str == "-------------");

	getline(result, str);
	CHECK(str == "-------------");
	getline(result, str);
	CHECK(str == "Title: word1 word2");
	getline(result, str);
	CHECK(str == "-------------");

	CHECK_FALSE(getline(result, str));
}

TEST_CASE("Editor insert paragraph tests")
{
	istringstream inStrm("insertParagraph\ninsertParagraph word\ninsertParagraph end word1 word2\ninsertParagraph 0 word3\nlist\nexit");
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
	getline(result, str);
	getline(result, str);
	getline(result, str);
	getline(result, str);
	getline(result, str);

	getline(result, str);
	CHECK(str == "Not specified position of the document");
	getline(result, str);
	CHECK(str == "Not specified position of the document");

	getline(result, str);
	CHECK(str == "-------------");
	getline(result, str);
	CHECK(str == "Title: ");
	getline(result, str);
	CHECK(str == "0. Paragraph: word3");
	getline(result, str);
	CHECK(str == "1. Paragraph: word1 word2");
	getline(result, str);
	CHECK(str == "-------------");
}

TEST_CASE("Editor insert image tests")
{
	istringstream inStrm("insertImage 0 TestResources/fox.jpg\ninsertImage 0 5 a TestResources/fox.jpg\ninsertImage 0 20 15 TestResources/fox.jpg\nlist\nexit");
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
	getline(result, str);
	getline(result, str);
	getline(result, str);
	getline(result, str);
	getline(result, str);

	getline(result, str);
	CHECK(str == "Not specified sizes of image");
	getline(result, str);
	CHECK(str == "Not specified sizes of image");

	getline(result, str);
	CHECK(str == "-------------");
	getline(result, str);
	CHECK(str == "Title: ");
	getline(result, str);
	CHECK(str == "0. Image: 20 15 7.jpg");
	getline(result, str);
	CHECK(str == "-------------");
}

TEST_CASE("Editor replace text of paragraph tests")
{
	istringstream inStrm("insertParagraph end word1\nreplaceText\nreplaceText word2\nreplaceText 0 word2\nlist\nexit");
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
	getline(result, str);
	getline(result, str);
	getline(result, str);
	getline(result, str);
	getline(result, str);

	getline(result, str);
	CHECK(str == "Not specified position of the document");
	getline(result, str);
	CHECK(str == "Not specified position of the document");

	getline(result, str);
	CHECK(str == "-------------");
	getline(result, str);
	CHECK(str == "Title: ");
	getline(result, str);
	CHECK(str == "0. Paragraph: word2");
	getline(result, str);
	CHECK(str == "-------------");
}

TEST_CASE("Editor resize image tests")
{
	istringstream inStrm("insertImage 0 200 150 TestResources/fox.jpg\nresizeImage 0 300 200\nlist\nexit");
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
	getline(result, str);
	getline(result, str);
	getline(result, str);
	getline(result, str);
	getline(result, str);

	getline(result, str);
	CHECK(str == "-------------");
	getline(result, str);
	CHECK(str == "Title: ");
	getline(result, str);
	CHECK(str == "0. Image: 300 200 8.jpg");
	getline(result, str);
	CHECK(str == "-------------");
}

TEST_CASE("Editor delete item tests")
{
	istringstream inStrm("insertParagraph end word\ndeleteItem\ndeleteItem abc\ndeleteItem 0\nlist\nexit");
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
	getline(result, str);
	getline(result, str);
	getline(result, str);
	getline(result, str);
	getline(result, str);

	getline(result, str);
	CHECK(str == "Not specified position of the document");
	getline(result, str);
	CHECK(str == "Not specified position of the document");

	getline(result, str);
	CHECK(str == "-------------");
	getline(result, str);
	CHECK(str == "Title: ");
	getline(result, str);
	CHECK(str == "-------------");
}

TEST_CASE("Editor save tests")
{
	istringstream inStrm("save TestResults\nexit");
	ostringstream outStrm;
	CEditor editor(inStrm, outStrm);

	editor.Start();

	ifstream fIn("TestResults/index.html");
	string str;

	getline(fIn, str);
	CHECK("<!DOCTYPE html>");
	getline(fIn, str);
	CHECK("<html>");
	getline(fIn, str);
	CHECK("  <head>");
	getline(fIn, str);
	CHECK("    <title></title>");
	getline(fIn, str);
	CHECK("  </head>");
	getline(fIn, str);
	CHECK("  <body>");
	getline(fIn, str);
	CHECK("    <h1></h1>");
	getline(fIn, str);
	CHECK("  </body>");
	getline(fIn, str);
	CHECK("</html>");
}