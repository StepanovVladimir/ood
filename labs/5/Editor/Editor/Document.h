#pragma once

#include "IDocument.h"
#include "History.h"

class CDocument : public IDocument
{
public:
	std::shared_ptr<IParagraph> InsertParagraph(const std::string& text,
		std::optional<size_t> position = std::nullopt) override;

	size_t GetItemsCount() const override;

	std::list<CDocumentItem>::const_iterator begin() const override;
	std::list<CDocumentItem>::iterator begin() override;
	std::list<CDocumentItem>::const_iterator end() const override;
	std::list<CDocumentItem>::iterator end() override;

	std::string GetTitle() const override;
	void SetTitle(const std::string& title) override;

	bool CanUndo() const override;
	void Undo() override;
	bool CanRedo() const override;
	void Redo() override;

private:
	std::string m_title;
	std::list<CDocumentItem> m_items;
	CHistory m_history;
};