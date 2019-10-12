#include "pch.h"
#include "History.h"

void CHistory::AddAndExecuteCommand(ICommandPtr&& command)
{
	if (m_nextCommandIndex < m_commands.size())
	{
		command->Execute();
		m_nextCommandIndex++;
		m_commands.resize(m_nextCommandIndex);
		m_commands.back() = move(command);
	}
	else
	{
		m_commands.emplace_back(nullptr);

		try
		{
			command->Execute();
			m_commands.back() = move(command);
			m_nextCommandIndex++;
		}
		catch (...)
		{
			m_commands.pop_back();
			throw;
		}
	}
}

bool CHistory::CanUndo() const
{
	return m_nextCommandIndex != 0;
}

void CHistory::Undo()
{
	if (CanUndo())
	{
		m_commands[m_nextCommandIndex - 1]->Unexecute();
		m_nextCommandIndex--;
	}
}

bool CHistory::CanRedo() const
{
	return m_nextCommandIndex != m_commands.size();
}

void CHistory::Redo()
{
	if (CanRedo())
	{
		m_commands[m_nextCommandIndex]->Execute();
		m_nextCommandIndex++;
	}
}