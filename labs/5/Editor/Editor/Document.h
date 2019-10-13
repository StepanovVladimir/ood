#pragma once

#include "IDocument.h"
#include "History.h"
#include <list>

class CDocument : public IDocument
{
public:
	std::shared_ptr<IParagraph> InsertParagraph(const std::string& text,
		std::optional<size_t> position = std::nullopt) override;

	size_t GetItemsCount() const override;

	/*CConstDocumentItem GetItem(size_t index) const override;
	CDocumentItem GetItem(size_t index) override;*/

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