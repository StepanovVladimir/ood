#include "pch.h"
#include "HasQuarterState.h"

using namespace std;

CHasQuarterState::CHasQuarterState(IGumballMachine& gumballMachine, ostream& strm)
	: m_gumballMachine(gumballMachine)
	, m_strm(strm)
{
}

void CHasQuarterState::InsertQuarter()
{
	if (m_gumballMachine.GetQuartersCount() < 5)
	{
		m_gumballMachine.AddQuarter();
	}
	else
	{
		m_strm << "You can't insert more than 5 quarters\n";
	}
}

void CHasQuarterState::EjectQuarter()
{
	m_gumballMachine.RemoveAllQuarters();
	m_gumballMachine.SetNoQuarterState();
}

void CHasQuarterState::TurnCrank()
{
	m_strm << "You turned...\n";
	m_gumballMachine.RemoveOneQuarter();
	m_gumballMachine.SetSoldState();
}

void CHasQuarterState::Dispense()
{
	m_strm << "No gumball dispensed\n";
}

string CHasQuarterState::ToString() const
{
	return "waiting for turn of crank";
}