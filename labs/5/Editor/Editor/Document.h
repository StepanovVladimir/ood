#pragma once

#include "IDocument.h"
#include "History.h"
#include <vector>

class CDocument : public IDocument
{
public:
	std::shared_ptr<IParagraph> InsertParagraph(const std::string& text,
		std::optional<size_t> position = std::nullopt) override;

	size_t GetItemsCount() const override;

	CConstDocumentItem GetItem(size_t index) const override;
	CDocumentItem GetItem(size_t index) override;

	void ReplaceText(const std::string& text, size_t index) override;
	void DeleteItem(size_t index) override;

	std::string GetTitle() const override;
	void SetTitle(const std::string& title) override;

	bool CanUndo() const override;
	void Undo() override;
	bool CanRedo() const override;
	void Redo() override;

	void Save(const std::string& path) const override;

private:
	std::string m_title;
	std::vector<CDocumentItem> m_items;
	CHistory m_history;

	std::string EncodeToHtml(const std::string& str) const;
};