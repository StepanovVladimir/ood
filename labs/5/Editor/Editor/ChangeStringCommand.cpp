#include "pch.h"
#include "ChangeStringCommand.h"

using namespace std;

CChangeStringCommand::CChangeStringCommand(string& target, const string& newValue)
	: m_target(target)
	, m_newValue(newValue)
{
}

void CChangeStringCommand::DoExecute()
{
	m_newValue.swap(m_target);
}

void CChangeStringCommand::DoUnexecute()
{
	m_newValue.swap(m_target);
}