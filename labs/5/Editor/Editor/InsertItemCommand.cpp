#include "pch.h"
#include "InsertItemCommand.h"

using namespace std;

CInsertItemCommand::CInsertItemCommand(list<CDocumentItem>& target, const CDocumentItem& item, optional<size_t> position)
	: m_target(target)
	, m_item(item)
	, m_position(position)
{
}

void CInsertItemCommand::DoExecute()
{
	if (m_position == nullopt)
	{
		m_target.push_back(m_item);
	}
	else
	{

	}
}

void CInsertItemCommand::DoUnexecute()
{
	if (m_position == nullopt)
	{
		m_target.pop_back();
	}
}