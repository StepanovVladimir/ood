#include "pch.h"
#include "Document.h"
#include "Paragraph.h"
#include "ChangeStringCommand.h"
#include "InsertItemCommand.h"
#include "ReplaceParagraphTextCommand.h"
#include "DeleteItemCommand.h"
#include <fstream>

using namespace std;

shared_ptr<IParagraph> CDocument::InsertParagraph(const string& text,
	optional<size_t> position)
{
	shared_ptr<CParagraph> paragraph = make_shared<CParagraph>(text);
	CDocumentItem item(make_shared<CParagraph>(text));

	m_history.AddAndExecuteCommand(make_unique<CInsertItemCommand>(m_items, item, position));
	
	return paragraph;
}

size_t CDocument::GetItemsCount() const
{
	return m_items.size();
}

list<CDocumentItem>::const_iterator CDocument::begin() const
{
	return m_items.begin();
}

list<CDocumentItem>::iterator CDocument::begin()
{
	return m_items.begin();
}

list<CDocumentItem>::const_iterator CDocument::end() const
{
	return m_items.end();
}

list<CDocumentItem>::iterator CDocument::end()
{
	return m_items.end();
}

void CDocument::ReplaceText(const std::string& text, size_t index)
{
	m_history.AddAndExecuteCommand(make_unique<CReplaceParagraphTextCommand>(m_items, text, index));
}

void CDocument::DeleteItem(size_t index)
{
	m_history.AddAndExecuteCommand(make_unique<CDeleteItemCommand>(m_items, index));
}

string CDocument::GetTitle() const
{
	return m_title;
}

void CDocument::SetTitle(const string& title)
{
	m_history.AddAndExecuteCommand(make_unique<CChangeStringCommand>(m_title, title));
}

bool CDocument::CanUndo() const
{
	return m_history.CanUndo();
}

void CDocument::Undo()
{
	m_history.Undo();
}

bool CDocument::CanRedo() const
{
	return m_history.CanRedo();
}

void CDocument::Redo()
{
	m_history.Redo();
}

void CDocument::Save(const string& path) const
{
	ofstream fOut(path + ".html");
	fOut << "<!DOCTYPE html>\n";
	fOut << "<html>\n";
	fOut << "  <head>\n";
	fOut << "    <title>" + m_title + "</title>\n";
	fOut << "  </head>\n";
	fOut << "  <body>\n";
	fOut << "    <h1>" + m_title + "</h1>\n";
	for (auto item : m_items)
	{
		fOut << "    <p>" + item.GetParagraph()->GetText() + "</p>\n";
	}
	fOut << "  </body>\n";
	fOut << "</html>\n";
}