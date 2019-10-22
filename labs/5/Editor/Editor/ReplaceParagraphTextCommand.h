#pragma once

#include "AbstractCommand.h"
#include "DocumentItem.h"
#include <vector>

class CReplaceParagraphTextCommand : public CAbstractCommand
{
public:
	CReplaceParagraphTextCommand(std::shared_ptr<IParagraph> target, const std::string& newText);

protected:
	void DoExecute() override;
	void DoUnexecute() override;

private:
	std::shared_ptr<IParagraph> m_target;
	std::string m_newText;
};