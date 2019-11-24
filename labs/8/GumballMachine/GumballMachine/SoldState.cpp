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
	if (m_gumballMachine.GetBallCount() == 0)
	{
		m_strm << "Oops, out of gumballs\n";
		m_gumballMachine.SetSoldOutState();
	}
	else
	{
		m_gumballMachine.SetNoQuarterState();
	}
}

string CSoldState::ToString() const
{
	return "delivering a gumball";
}