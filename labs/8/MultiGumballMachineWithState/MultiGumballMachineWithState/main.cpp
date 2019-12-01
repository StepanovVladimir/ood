#include "pch.h"
#include "GumballMachine.h"
#include "Menu.h"

using namespace std;

unsigned ReadUnsigned(istream& in)
{
	unsigned count;
	in >> count;

	if (!in)
	{
		throw runtime_error("You didn't enter a number");
	}

	return count;
}

CMenu InitMenu(CGumballMachine& gumballMachine)
{
	CMenu menu;
	menu.AddItem("help", "Help", [&](istream&) { menu.ShowInstructions(); });
	menu.AddItem("exit", "Exit", [&](istream&) { menu.Exit(); });

	menu.AddItem("info", "Prints info about the machine", [&](istream&) { cout << gumballMachine.ToString(); });

	menu.AddItem("insertQuarter", "Inserts a quarter into the machine", [&](istream&) { gumballMachine.InsertQuarter(); });
	menu.AddItem("ejectQuarter", "Ejects a quarter out of the machine", [&](istream&) { gumballMachine.EjectQuarter(); });
	menu.AddItem("turnCrank", "Turn the crank after inserting the quarter to get the gumball", [&](istream&) { gumballMachine.TurnCrank(); });
	menu.AddItem("refill", "refill the supply of balls. Args: <count>", [&](istream& in) {
		try
		{
			unsigned count = ReadUnsigned(in);
			gumballMachine.Refill(count);
		}
		catch (runtime_error& exc)
		{
			cout << exc.what() << endl;
		}
	});
	
	return menu;
}

int main()
{
	CGumballMachine gumballMachine;
	CMenu menu = InitMenu(gumballMachine);
	menu.Run();
}