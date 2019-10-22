#include "pch.h"
#include "DeleteItemCommand.h"

using namespace std;

CDeleteItemCommand::CDeleteItemCommand(vector<CDocumentItem>& target, size_t index)
	: m_target(target)
	, m_index(index)
	, m_item(GetDocumentItem())
{
}

void CDeleteItemCommand::DoExecute()
{
	m_target.erase(m_target.begin() + m_index);
}

void CDeleteItemCommand::DoUnexecute()
{
	m_target.insert(m_target.begin() + m_index, m_item);
}

CDocumentItem CDeleteItemCommand::GetDocumentItem()
{
	if (m_index >= m_target.size())
	{
		throw runtime_error("The item number exceeds the number of items in the document");
	}
	return m_target[m_index];
}