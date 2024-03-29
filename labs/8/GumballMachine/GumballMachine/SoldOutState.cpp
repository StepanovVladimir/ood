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
	m_strm << "You can't eject, you haven't inserted a quarter yet\n";
}

void CSoldOutState::TurnCrank()
{
	m_strm << "You turned but there's no gumballs\n";
}

void CSoldOutState::Dispense()
{
	m_strm << "No gumball dispensed\n";
}

string CSoldOutState::ToString() const
{
	return "sold out";
}