#pragma once

#include "AbstractCommand.h"
#include "DocumentItem.h"
#include <list>

class CReplaceParagraphTextCommand : public CAbstractCommand
{
public:
	CReplaceParagraphTextCommand(std::list<CDocumentItem>& target, const std::string& newText, size_t index);

protected:
	void DoExecute() override;
	void DoUnexecute() override;

private:
	std::list<CDocumentItem>& m_target;
	std::string m_newText;
	size_t m_index;

	std::list<CDocumentItem>::iterator GetIterator();
};