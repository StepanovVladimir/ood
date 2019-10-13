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
	m_outStrm << m_document->GetTitle() << endl;
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