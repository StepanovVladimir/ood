#pragma once

#include "AbstractCommand.h"
#include "DocumentItem.h"
#include <list>

class CDeleteItemCommand : public CAbstractCommand
{
public:
	CDeleteItemCommand(std::list<CDocumentItem>& target, size_t index);

protected:
	void DoExecute() override;
	void DoUnexecute() override;

private:
	std::list<CDocumentItem>& m_target;
	size_t m_index;
	CDocumentItem m_item;

	CDocumentItem GetDocumentItem();
	std::list<CDocumentItem>::iterator GetIterator();
};