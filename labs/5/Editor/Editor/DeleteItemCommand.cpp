#include "pch.h"
#include "DeleteItemCommand.h"

using namespace std;

CDeleteItemCommand::CDeleteItemCommand(list<CDocumentItem>& target, size_t index)
	: m_target(target)
	, m_index(index)
	, m_item(GetDocumentItem())
{
}

void CDeleteItemCommand::DoExecute()
{
	m_target.erase(GetIterator());
}

void CDeleteItemCommand::DoUnexecute()
{
	m_target.insert(GetIterator(), m_item);
}

CDocumentItem CDeleteItemCommand::GetDocumentItem()
{
	if (m_index >= m_target.size())
	{
		throw runtime_error("The item number exceeds the number of items in the document");
	}
	return *GetIterator();
}

list<CDocumentItem>::iterator CDeleteItemCommand::GetIterator()
{
	auto iter = m_target.begin();
	for (size_t i = 0; i < m_index; i++)
	{
		iter++;
	}
	return iter;
}