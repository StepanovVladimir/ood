#include "pch.h"
#include "ReplaceParagraphTextCommand.h"

using namespace std;

CReplaceParagraphTextCommand::CReplaceParagraphTextCommand(list<CDocumentItem>& target, const string& newText, size_t index)
	: m_target(target)
	, m_newText(newText)
	, m_index(index)
{
	if (m_index >= m_target.size())
	{
		throw runtime_error("The item number exceeds the number of items in the document");
	}
}

void CReplaceParagraphTextCommand::DoExecute()
{
	m_newText.swap(GetIterator()->GetParagraph()->GetText());
}

void CReplaceParagraphTextCommand::DoUnexecute()
{
	m_newText.swap(GetIterator()->GetParagraph()->GetText());
}

list<CDocumentItem>::iterator CReplaceParagraphTextCommand::GetIterator()
{
	auto iter = m_target.begin();
	for (size_t i = 0; i < m_index; i++)
	{
		iter++;
	}
	return iter;
}