#include "pch.h"
#include "SoldState.h"

using namespace std;

CSoldState::CSoldState(IGumballMachine& gumballMachine, ostream& strm)
	: m_gumballMachine(gumballMachine)
	, m_strm(strm)
{
}

void CSoldState::InsertQuarter()
{
	m_strm << "Please wait, we're already giving you a gumball\n";
}

void CSoldState::EjectQuarter()
{
	m_strm << "Sorry you already turned the crank\n";
}

void CSoldState::TurnCrank()
{
	m_strm << "Turning twice doesn't get you another gumball\n";
}

void CSoldState::Dispense()
{
	m_gumballMachine.ReleaseBall();
	if (m_gumballMachine.GetBallsCount() == 0)
	{
		m_strm << "Oops, out of gumballs\n";
		m_gumballMachine.SetSoldOutState();
	}
	else if (m_gumballMachine.GetQuartersCount() > 0)
	{
		m_gumballMachine.SetHasQuarterState();
	}
	else
	{
		m_gumballMachine.SetNoQuarterState();
	}
}

void CSoldState::Refill(unsigned numBalls)
{
	m_strm << "You can not fill the machine with gumballs during the issuance of gumball";
}

string CSoldState::ToString() const
{
	return "delivering a gumball";
}