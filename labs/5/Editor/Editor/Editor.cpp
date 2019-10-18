#include "pch.h"
#include "Editor.h"
#include "Document.h"

using namespace std;

CEditor::CEditor(istream& inStrm, ostream& outStrm)
	: m_menu(inStrm, outStrm)
	, m_outStrm(outStrm)
	, m_document(make_unique<CDocument>())
{
	m_menu.AddItem("help", "Help", [this](istream&) { m_menu.ShowInstructions(); });
	m_menu.AddItem("exit", "Exit", [this](istream&) { m_menu.Exit(); });

	AddMenuItem("insertParagraph", "Inserts paragraph. Args: <position>|end <text>", &CEditor::InsertParagraph);
	AddMenuItem("setTitle", "Changes title. Args: <new title>", &CEditor::SetTitle);
	AddMenuItem("list", "Show document", &CEditor::List);
	AddMenuItem("undo", "Undo command", &CEditor::Undo);
	AddMenuItem("redo", "Redo undone command", &CEditor::Redo);
}

void CEditor::Start()
{
	m_menu.Run();
}

void CEditor::AddMenuItem(const string& shortcut, const string& description, MenuHandler handler)
{
	m_menu.AddItem(shortcut, description, bind(handler, this, placeholders::_1));
}

void CEditor::InsertParagraph(istream& in)
{
	string strPosition;
	optional<size_t> position;

	in >> strPosition;
	if (!in)
	{
		m_outStrm << "Not specified position of the document\n";
		return;
	}

	if (strPosition != "end")
	{
		try
		{
			position = stoul(strPosition);
		}
		catch (...)
		{
			m_outStrm << "Not specified position of the document\n";
			return;
		}
	}

	string head;
	string tail;
	if (in >> head)
	{
		getline(in, tail);
	}
	string text = head + tail;
	
	try
	{
		m_document->InsertParagraph(text, position);
	}
	catch (runtime_error& exc)
	{
		m_outStrm << exc.what();
	}
}

void CEditor::SetTitle(istream& in)
{
	string head;
	string tail;

	if (in >> head)
	{
		getline(in, tail);
	}
	string title = head + tail;

	m_document->SetTitle(title);
}

void CEditor::List(istream&)
{
	m_outStrm << "-------------" << endl;
	m_outStrm << "Title: " << m_document->GetTitle() << endl;
	size_t i = 0;
	for (CDocumentItem& item : *m_document)
	{
		m_outStrm << i << ". Paragraph: " << item.GetParagraph()->GetText() << endl;
		i++;
	}
	m_outStrm << "-------------" << endl;
}

void CEditor::Undo(istream&)
{
	if (m_document->CanUndo())
	{
		m_document->Undo();
	}
	else
	{
		m_outStrm << "Can't undo" << endl;
	}
}

void CEditor::Redo(istream&)
{
	if (m_document->CanRedo())
	{
		m_document->Redo();
	}
	else
	{
		m_outStrm << "Can't redo" << endl;
	}
}