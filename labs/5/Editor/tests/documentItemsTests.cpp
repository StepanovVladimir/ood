#include "../../../../catch2/catch.hpp"
#include "../Editor/DocumentItem.h"
#include "../Editor/Paragraph.h"
#include "../Editor/Image.h"
#include <filesystem>

using namespace std;

TEST_CASE("Paragraph tests")
{
	CParagraph paragraph("first");
	CHECK(paragraph.GetText() == "first");

	paragraph.SetText("second");
	CHECK(paragraph.GetText() == "second");
}

TEST_CASE("Image invalid arguments tests")
{
	CHECK_THROWS_AS(CImage("nonexistentFile", 200, 150), runtime_error);
	CHECK_THROWS_AS(CImage("TestResources/text.txt", 200, 150), runtime_error);
	CHECK_THROWS_AS(CImage("TestResources/fox.jpg", 0, 150), runtime_error);
	CHECK_THROWS_AS(CImage("TestResources/fox.jpg", 200, 10001), runtime_error);
}

TEST_CASE("Image tests")
{
	SECTION("Work with images")
	{
		CImage image1("TestResources/fox.jpg", 200, 150);

		CHECK(image1.GetPath() == "2.jpg");
		CHECK(image1.GetWidth() == 200);
		CHECK(image1.GetHeight() == 150);

		CHECK(filesystem::exists(image1.GetPath()));

		image1.Resize(1, 10000);

		CHECK(image1.GetWidth() == 1);
		CHECK(image1.GetHeight() == 10000);

		CImage image2("TestResources/fox.jpg", 200, 150);

		CHECK(image2.GetPath() == "3.jpg");
		CHECK(filesystem::exists(image2.GetPath()));
	}

	SECTION("Check delete images")
	{
		CHECK_FALSE(filesystem::exists("2.jpg"));
		CHECK_FALSE(filesystem::exists("3.jpg"));
	}
}

TEST_CASE("Document item tests")
{
	shared_ptr<IParagraph> paragraph = make_shared<CParagraph>("text");
	CConstDocumentItem constDocumentItem(paragraph);

	CHECK(constDocumentItem.GetImage() == nullptr);

	shared_ptr<const IParagraph> constParagraph = constDocumentItem.GetParagraph();
	CHECK(constParagraph->GetText() == "text");

	CDocumentItem documentItem(paragraph);

	CHECK(documentItem.GetImage() == nullptr);

	paragraph = documentItem.GetParagraph();
	CHECK(paragraph->GetText() == "text");
}