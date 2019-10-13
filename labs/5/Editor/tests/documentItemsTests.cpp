#include "../../../../catch2/catch.hpp"
#include "../Editor/DocumentItem.h"
#include "../Editor/Paragraph.h"

using namespace std;

TEST_CASE("Paragraph tests")
{
	CParagraph paragraph("first");
	CHECK(paragraph.GetText() == "first");

	paragraph.SetText("second");
	CHECK(paragraph.GetText() == "second");
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