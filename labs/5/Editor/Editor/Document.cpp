#include "pch.h"
#include "Document.h"
#include "ChangeStringCommand.h"
#include "Paragraph.h"

using namespace std;

shared_ptr<IParagraph> CDocument::InsertParagraph(const string& text,
	optional<size_t> position)
{
	CDocumentItem documentItem(make_shared<CParagraph>(text));
	//m_history.AddAndExecuteCommand(make_unique<CChangeStringCommand>(m_items, text));
	return nullptr;
}

size_t CDocument::GetItemsCount() const
{
	return 0;
}

/*CConstDocumentItem CDocument::GetItem(size_t index) const
{
	return CConstDocumentItem();
}

CDocumentItem CDocument::GetItem(size_t index)
{
	return CDocumentItem();
}*/

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