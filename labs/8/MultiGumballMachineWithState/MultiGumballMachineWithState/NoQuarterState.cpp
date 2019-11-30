#include "pch.h"
#include "NoQuarterState.h"

using namespace std;

CNoQuarterState::CNoQuarterState(IGumballMachine& gumballMachine, ostream& strm)
	: m_gumballMachine(gumballMachine)
	, m_strm(strm)
{
}

void CNoQuarterState::InsertQuarter()
{
	m_gumballMachine.AddQuarter();
	m_gumballMachine.SetHasQuarterState();
}

void CNoQuarterState::EjectQuarter()
{
	m_strm << "You haven't inserted a quarter\n";
}

void CNoQuarterState::TurnCrank()
{
	m_strm << "You turned but there's no quarter\n";
}

void CNoQuarterState::Dispense()
{
	m_strm << "You need to pay first\n";
}

void CNoQuarterState::Refill(unsigned numBalls)
{
	m_gumballMachine.AddBalls(numBalls);
}

string CNoQuarterState::ToString() const
{
	return "waiting for quarter";
}