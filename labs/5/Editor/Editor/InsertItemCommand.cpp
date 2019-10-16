#include "pch.h"
#include "InsertItemCommand.h"

using namespace std;

CInsertItemCommand::CInsertItemCommand(list<CDocumentItem>& target, const CDocumentItem& item, optional<size_t> position)
	: m_target(target)
	, m_item(item)
	, m_position(position)
{
	if (m_position != nullopt && m_position.value() > m_target.size())
	{
		throw runtime_error("The item number exceeds the number of items in the document");
	}
}

void CInsertItemCommand::DoExecute()
{
	if (m_position == nullopt)
	{
		m_target.push_back(m_item);
	}
	else
	{
		m_target.insert(GetIterator(), m_item);
	}
}

void CInsertItemCommand::DoUnexecute()
{
	if (m_position == nullopt)
	{
		m_target.pop_back();
	}
	else
	{
		m_target.erase(GetIterator());
	}
}

list<CDocumentItem>::iterator CInsertItemCommand::GetIterator()
{
	auto iter = m_target.begin();
	for (size_t i = 0; i < m_position; i++)
	{
		iter++;
	}
	return iter;
}