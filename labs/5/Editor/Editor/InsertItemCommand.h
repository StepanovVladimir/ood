#pragma once

#include "AbstractCommand.h"
#include "DocumentItem.h"
#include <vector>
#include <optional>

class CInsertItemCommand : public CAbstractCommand
{
public:
	CInsertItemCommand(std::vector<CDocumentItem>& target, const CDocumentItem& item, std::optional<size_t> position);
	CInsertItemCommand(std::vector<CDocumentItem>& target, int width, int height, std::optional<size_t> position);

protected:
	void DoExecute() override;
	void DoUnexecute() override;

private:
	std::vector<CDocumentItem>& m_target;
	CDocumentItem m_item;
	std::optional<size_t> m_position;
};