#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <functional>

class CMenu
{
public:
	using Command = std::function<void(std::istream& args)>;
	
	CMenu(std::istream& inStrm = std::cin, std::ostream& outStrm = std::cout);

	void AddItem(const std::string& shortcut, const std::string& description, const Command& command);
	void Run();
	void ShowInstructions() const;
	void Exit();

private:
	struct Item
	{
		Item(const std::string& shortcut, const std::string& description, const Command& command)
			: shortcut(shortcut)
			, description(description)
			, command(command)
		{
		}

		std::string shortcut;
		std::string description;
		Command command;
	};

	std::istream& m_inStrm;
	std::ostream& m_outStrm;
	std::vector<Item> m_items;
	bool m_exit = false;

	bool ExecuteCommand(const std::string& command);
};