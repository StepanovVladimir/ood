#pragma once

#include "IParagraph.h"
#include "IImage.h"
#include "DocumentItem.h"
#include <list>
#include <optional>

class IDocument
{
public:
	virtual ~IDocument() = default;

	virtual std::shared_ptr<IParagraph> InsertParagraph(const std::string& text,
		std::optional<size_t> position = std::nullopt) = 0;
	/*virtual std::shared_ptr<IImage> InsertImage(const std::string& path, int width, int height,
		std::optional<size_t> position = std::nullopt) = 0;*/

	virtual size_t GetItemsCount() const = 0;

	virtual std::list<CDocumentItem>::const_iterator begin() const = 0;
	virtual std::list<CDocumentItem>::iterator begin() = 0;
	virtual std::list<CDocumentItem>::const_iterator end() const = 0;
	virtual std::list<CDocumentItem>::iterator end() = 0;

	virtual void ReplaceText(const std::string& text, size_t index) = 0;
	virtual void DeleteItem(size_t index) = 0;

	virtual std::string GetTitle() const = 0;
	virtual void SetTitle(const std::string& title) = 0;

	virtual bool CanUndo() const = 0;
	virtual void Undo() = 0;
	virtual bool CanRedo() const = 0;
	virtual void Redo() = 0;

	virtual void Save(const std::string& path) const = 0;
};