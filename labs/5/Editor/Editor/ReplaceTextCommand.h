#pragma once

#include "AbstractCommand.h"
#include "IParagraph.h"

class CReplaceTextCommand : public CAbstractCommand
{
public:
	CReplaceTextCommand(std::shared_ptr<IParagraph> target, const std::string& newText);

protected:
	void DoExecute() override;
	void DoUnexecute() override;

private:
	std::shared_ptr<IParagraph> m_target;
	std::string m_newText;
};