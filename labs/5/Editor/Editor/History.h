#pragma once

#include "ICommand.h"
#include <deque>

class CHistory
{
public:
	void AddAndExecuteCommand(ICommandPtr&& command);
	bool CanUndo() const;
	void Undo();
	bool CanRedo() const;
	void Redo();

private:
	std::deque<ICommandPtr> m_commands;
	size_t m_nextCommandIndex = 0;
};