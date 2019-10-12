#pragma once

#include "AbstractCommand.h"
#include <string>

class CChangeStringCommand : public CAbstractCommand
{
public:
	CChangeStringCommand(std::string& target, const std::string& newValue);

protected:
	void DoExecute() override;
	void DoUnexecute() override;

private:
	std::string& m_target;
	std::string m_newValue;
};