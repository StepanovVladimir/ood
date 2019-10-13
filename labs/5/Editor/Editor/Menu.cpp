#include "pch.h"
#include "Menu.h"
#include <sstream>
#include <algorithm>

using namespace std;

CMenu::CMenu(istream& inStrm, ostream& outStrm)
	: m_inStrm(inStrm)
	, m_outStrm(outStrm)
{
}

void CMenu::AddItem(const string& shortcut, const string& description, const Command& command)
{
	m_items.emplace_back(shortcut, description, command);
}

void CMenu::Run()
{
	ShowInstructions();

	string command;
	while (getline(m_inStrm, command) && ExecuteCommand(command))
	{
	}
}

void CMenu::ShowInstructions() const
{
	m_outStrm << "Commands list:\n";
	for (auto& item : m_items)
	{
		m_outStrm << "  " << item.shortcut << ": " << item.description << "\n";
	}
}

void CMenu::Exit()
{
	m_exit = true;
}

bool CMenu::ExecuteCommand(const string& command)
{
	istringstream iss(command);
	string name;
	iss >> name;

	m_exit = false;
	auto it = find_if(m_items.begin(), m_items.end(), [&](const Item& item) {
		return item.shortcut == name;
	});

	if (it != m_items.end())
	{
		it->command(iss);
	}
	else
	{
		m_outStrm << "Unknown command\n";
	}
	return !m_exit;
}