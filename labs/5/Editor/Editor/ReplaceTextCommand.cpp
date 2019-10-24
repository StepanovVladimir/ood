#include "pch.h"
#include "ReplaceTextCommand.h"

using namespace std;

CReplaceTextCommand::CReplaceTextCommand(shared_ptr<IParagraph> target, const string& newText)
	: m_target(target)
	, m_newText(newText)
{
}

void CReplaceTextCommand::DoExecute()
{
	string tmpStr = m_target->GetText();
	m_newText.swap(tmpStr);
	m_target->SetText(tmpStr);
}

void CReplaceTextCommand::DoUnexecute()
{
	string tmpStr = m_target->GetText();
	m_newText.swap(tmpStr);
	m_target->SetText(tmpStr);
}