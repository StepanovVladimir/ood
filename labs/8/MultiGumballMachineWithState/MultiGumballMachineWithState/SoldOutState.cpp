#include "pch.h"
#include "SoldOutState.h"

using namespace std;

CSoldOutState::CSoldOutState(IGumballMachine& gumballMachine, ostream& strm)
	: m_gumballMachine(gumballMachine)
	, m_strm(strm)
{
}

void CSoldOutState::InsertQuarter()
{
	m_strm << "You can't insert a quarter, the machine is sold out\n";
}

void CSoldOutState::EjectQuarter()
{
	if (m_gumballMachine.GetQuartersCount() > 0)
	{
		m_gumballMachine.RemoveAllQuarters();
	}
	else
	{
		m_strm << "You can't eject, you haven't inserted a quarter yet\n";
	}
}

void CSoldOutState::TurnCrank()
{
	m_strm << "You turned but there's no gumballs\n";
}

void CSoldOutState::Dispense()
{
	m_strm << "No gumball dispensed\n";
}

void CSoldOutState::Refill(unsigned numBalls)
{
	m_gumballMachine.AddBalls(numBalls);
	if (m_gumballMachine.GetBallsCount() > 0)
	{
		m_gumballMachine.GetQuartersCount() > 0 ? m_gumballMachine.SetHasQuarterState()
			: m_gumballMachine.SetNoQuarterState();
	}
}

string CSoldOutState::ToString() const
{
	return "sold out";
}