#pragma once

#include "IDocument.h"
#include "History.h"

class CDocument : public IDocument
{
public:
	std::string GetTitle() const override;
	void SetTitle(const std::string & title) override;

	bool CanUndo() const override;
	void Undo() override;
	bool CanRedo() const override;
	void Redo() override;

private:
	std::string m_title;
	CHistory m_history;
};