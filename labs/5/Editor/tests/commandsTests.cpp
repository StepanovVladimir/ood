#define CATCH_CONFIG_MAIN
#include "../../../../catch2/catch.hpp"
#include "../Editor/ChangeStringCommand.h"
#include "../Editor/InsertItemCommand.h"
#include "../Editor/ReplaceParagraphTextCommand.h"
#include "../Editor/DeleteItemCommand.h"
#include "../Editor/Paragraph.h"

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

TEST_CASE("Insert item command tests")
{
	vector<CDocumentItem> items;
	CDocumentItem item1(make_shared<CParagraph>("first"));

	CHECK_THROWS_AS(CInsertItemCommand(items, item1, 1), runtime_error);

	CInsertItemCommand command1(items, item1, nullopt);
	CHECK(items.empty());

	command1.Execute();
	CHECK(items.size() == 1);
	CHECK(items[0].GetParagraph()->GetText() == "first");

	command1.Unexecute();
	CHECK(items.empty());

	CDocumentItem item2(make_shared<CParagraph>("second"));
	CInsertItemCommand command2(items, item2, 0);

	command2.Execute();
	CHECK(items.size() == 1);
	CHECK(items[0].GetParagraph()->GetText() == "second");

	CDocumentItem item3(make_shared<CParagraph>("third"));
	CInsertItemCommand command3(items, item3, 0);

	command3.Execute();
	CHECK(items.size() == 2);
	CHECK(items[0].GetParagraph()->GetText() == "third");
	CHECK(items[1].GetParagraph()->GetText() == "second");

	command3.Unexecute();
	CHECK(items.size() == 1);
	CHECK(items[0].GetParagraph()->GetText() == "second");

	command2.Unexecute();
	CHECK(items.empty());
}

TEST_CASE("Replace paragraph text command tests")
{
	shared_ptr<IParagraph> paragraph = make_shared<CParagraph>("first");
	CReplaceParagraphTextCommand command(paragraph, "second");
	
	command.Execute();
	CHECK(paragraph->GetText() == "second");

	command.Unexecute();
	CHECK(paragraph->GetText() == "first");
}

TEST_CASE("Delete item command tests")
{
	vector<CDocumentItem> items;

	CHECK_THROWS_AS(CDeleteItemCommand(items, 0), runtime_error);

	items.push_back(CDocumentItem(make_shared<CParagraph>("first")));
	items.push_back(CDocumentItem(make_shared<CParagraph>("second")));

	CDeleteItemCommand command1(items, 0);
	CHECK(items.size() == 2);
	CHECK(items[0].GetParagraph()->GetText() == "first");
	CHECK(items[1].GetParagraph()->GetText() == "second");

	command1.Execute();
	CHECK(items.size() == 1);
	CHECK(items[0].GetParagraph()->GetText() == "second");

	command1.Unexecute();
	CHECK(items.size() == 2);
	CHECK(items[0].GetParagraph()->GetText() == "first");
	CHECK(items[1].GetParagraph()->GetText() == "second");
	
	CDeleteItemCommand command2(items, 1);
	command2.Execute();
	CHECK(items.size() == 1);
	CHECK(items[0].GetParagraph()->GetText() == "first");

	command2.Unexecute();
	CHECK(items.size() == 2);
	CHECK(items[0].GetParagraph()->GetText() == "first");
	CHECK(items[1].GetParagraph()->GetText() == "second");
}