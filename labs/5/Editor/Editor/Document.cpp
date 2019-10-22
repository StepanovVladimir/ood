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

CConstDocumentItem CDocument::GetItem(size_t index) const
{
	return m_items[index];
}

CDocumentItem CDocument::GetItem(size_t index)
{
	return m_items[index];
}

void CDocument::ReplaceText(const std::string& text, size_t index)
{
	if (index >= m_items.size())
	{
		throw runtime_error("The item number exceeds the number of items in the document");
	}
	m_history.AddAndExecuteCommand(make_unique<CReplaceParagraphTextCommand>(m_items[index].GetParagraph(), text));
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

	if (!fOut.is_open())
	{
		throw runtime_error("There is no such path");
	}

	string htmlTitle = EncodeToHtml(m_title);
	fOut << "<!DOCTYPE html>\n";
	fOut << "<html>\n";
	fOut << "  <head>\n";
	fOut << "    <title>" + htmlTitle + "</title>\n";
	fOut << "  </head>\n";
	fOut << "  <body>\n";
	fOut << "    <h1>" + htmlTitle + "</h1>\n";
	for (auto item : m_items)
	{
		fOut << "    <p>" + EncodeToHtml(item.GetParagraph()->GetText()) + "</p>\n";
	}
	fOut << "  </body>\n";
	fOut << "</html>\n";
}

string CDocument::EncodeToHtml(const string& str) const
{
	string result;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] == '"')
		{
			result += "&quot;";
		}
		else if (str[i] == '\'')
		{
			result += "&apos;";
		}
		else if (str[i] == '<')
		{
			result += "&lt;";
		}
		else if (str[i] == '>')
		{
			result += "&gt;";
		}
		else if (str[i] == '&')
		{
			result += "&amp;";
		}
		else
		{
			result += str[i];
		}
	}
	return result;
}