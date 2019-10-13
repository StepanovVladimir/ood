#pragma once

#include "AbstractCommand.h"
#include "DocumentItem.h"
#include <list>
#include <optional>

class CInsertItemCommand : public CAbstractCommand
{
public:
	CInsertItemCommand(std::list<CDocumentItem>& target, const CDocumentItem& item, std::optional<size_t> position);

protected:
	void DoExecute() override;
	void DoUnexecute() override;

private:
	std::list<CDocumentItem>& m_target;
	CDocumentItem m_item;
	std::optional<size_t> m_position;
};