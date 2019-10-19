#pragma once

#include "Menu.h"
#include "IDocument.h"

class CEditor
{
public:
	CEditor(std::istream& inStrm = std::cin, std::ostream& outStrm = std::cout);
	
	void Start();

private:
	typedef void (CEditor::*MenuHandler)(std::istream& in);

	CMenu m_menu;
	std::ostream& m_outStrm;
	std::unique_ptr<IDocument> m_document;

	void AddMenuItem(const std::string& shortcut, const std::string& description, MenuHandler handler);

	void InsertParagraph(std::istream& in);
	void SetTitle(std::istream& in);
	void List(std::istream&);
	void ReplaceText(std::istream& in);
	void DeleteItem(std::istream& in);
	void Undo(std::istream&);
	void Redo(std::istream&);
};