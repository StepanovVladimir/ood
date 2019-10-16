#include "pch.h"
#include "Document.h"
#include "Paragraph.h"
#include "ChangeStringCommand.h"
#include "InsertItemCommand.h"

using namespace std;

shared_ptr<IParagraph> CDocument::InsertParagraph(const string& text,
	optional<size_t> position)
{
	shared_ptr<CParagraph> paragraph = make_shared<CParagraph>(text);
	CDocumentItem item(paragraph);
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