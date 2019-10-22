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
	AddMenuItem("replaceText", "Replaces text of paragraph. Args: <position> <new text>", &CEditor::ReplaceText);
	AddMenuItem("deleteItem", "Deletes document item. Args: <position>", &CEditor::DeleteItem);
	AddMenuItem("undo", "Undo command", &CEditor::Undo);
	AddMenuItem("redo", "Redo undone command", &CEditor::Redo);
	AddMenuItem("save", "Saves document. Args: <path>", &CEditor::Save);
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
	in >> strPosition;
	if (!in)
	{
		m_outStrm << "Not specified position of the document\n";
		return;
	}

	try
	{
		optional<size_t> position;
		if (strPosition != "end")
		{
			position = StringToUnsigned(strPosition);
		}

		string head;
		string tail;
		if (in >> head)
		{
			getline(in, tail);
		}
		string text = head + tail;

		m_document->InsertParagraph(text, position);
	}
	catch (runtime_error& exc)
	{
		m_outStrm << exc.what() << endl;
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
	for (size_t i = 0; i < m_document->GetItemsCount(); i++)
	{
		m_outStrm << i << ". Paragraph: " << m_document->GetItem(i).GetParagraph()->GetText() << endl;
	}
	m_outStrm << "-------------" << endl;
}

void CEditor::ReplaceText(std::istream& in)
{
	try
	{
		size_t index = ReadUnsigned(in);

		string head;
		string tail;
		if (in >> head)
		{
			getline(in, tail);
		}
		string text = head + tail;

		m_document->ReplaceText(text, index);
	}
	catch (runtime_error& exc)
	{
		m_outStrm << exc.what() << endl;
	}
}

void CEditor::DeleteItem(istream& in)
{
	try
	{
		size_t index = ReadUnsigned(in);
		m_document->DeleteItem(index);
	}
	catch (runtime_error& exc)
	{
		m_outStrm << exc.what() << endl;
	}
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

void CEditor::Save(istream& in)
{
	string head;
	string tail;
	if (in >> head)
	{
		getline(in, tail);
	}
	string path = head + tail;

	try
	{
		m_document->Save(path);
	}
	catch (runtime_error& exc)
	{
		m_outStrm << exc.what() << endl;;
	}
}

size_t CEditor::ReadUnsigned(istream& in) const
{
	string str;
	in >> str;

	if (!in)
	{
		throw runtime_error("Not specified position of the document");
	}

	return StringToUnsigned(str);
}

size_t CEditor::StringToUnsigned(const std::string& str) const
{
	int result;
	try
	{
		result = stoi(str);
	}
	catch (...)
	{
		throw runtime_error("Not specified position of the document");
	}

	if (result < 0)
	{
		throw runtime_error("Position cannot be a negative number");
	}

	return (size_t)result;
}