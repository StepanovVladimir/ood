#pragma once

#include "AbstractCommand.h"
#include "DocumentItem.h"
#include <vector>

class CDeleteItemCommand : public CAbstractCommand
{
public:
	CDeleteItemCommand(std::vector<CDocumentItem>& target, size_t index);

protected:
	void DoExecute() override;
	void DoUnexecute() override;

private:
	std::vector<CDocumentItem>& m_target;
	size_t m_index;
	CDocumentItem m_item;

	CDocumentItem GetDocumentItem();
};