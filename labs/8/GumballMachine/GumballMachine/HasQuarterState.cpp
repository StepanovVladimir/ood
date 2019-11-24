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
	m_strm << "You can't insert another quarter\n";
}

void CHasQuarterState::EjectQuarter()
{
	m_strm << "Quarter returned\n";
	m_gumballMachine.SetNoQuarterState();
}

void CHasQuarterState::TurnCrank()
{
	m_strm << "You turned...\n";
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