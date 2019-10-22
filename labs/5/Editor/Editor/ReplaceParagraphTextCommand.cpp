#include "pch.h"
#include "ReplaceParagraphTextCommand.h"

using namespace std;

CReplaceParagraphTextCommand::CReplaceParagraphTextCommand(shared_ptr<IParagraph> target, const string& newText)
	: m_target(target)
	, m_newText(newText)
{
}

void CReplaceParagraphTextCommand::DoExecute()
{
	string tmpStr = m_target->GetText();
	m_newText.swap(tmpStr);
	m_target->SetText(tmpStr);
}

void CReplaceParagraphTextCommand::DoUnexecute()
{
	string tmpStr = m_target->GetText();
	m_newText.swap(tmpStr);
	m_target->SetText(tmpStr);
}