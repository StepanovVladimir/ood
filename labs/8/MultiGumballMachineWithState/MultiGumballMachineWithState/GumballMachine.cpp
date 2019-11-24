#include "pch.h"
#include "GumballMachine.h"
#include "SoldOutState.h"
#include "NoQuarterState.h"
#include "SoldState.h"
#include "HasQuarterState.h"

using namespace std;

CGumballMachine::CGumballMachine(unsigned numBalls, ostream& strm)
	: m_ballsCount(numBalls)
	, m_strm(strm)
{
	if (m_ballsCount > 0)
	{
		SetNoQuarterState();
	}
	else
	{
		SetSoldOutState();
	}
}

void CGumballMachine::InsertQuarter()
{
	m_currentState->InsertQuarter();
}

void CGumballMachine::EjectQuarter()
{
	m_currentState->EjectQuarter();
}

void CGumballMachine::TurnCrank()
{
	m_currentState->TurnCrank();
	m_currentState->Dispense();
}

string CGumballMachine::ToString() const
{
	string str = "Mighty Gumball, Inc.\n";
	str += "C++-enabled Standing Gumball Model #2016 (with state)\n";
	str += "Inventory: " + to_string(m_ballsCount) + " gumball" + (m_ballsCount != 1 ? "s, " : ", ");
	str += to_string(m_quartersCount) + " quarter" + (m_quartersCount != 1 ? "s\n" : "\n");
	str += "Machine is " + m_currentState->ToString() + '\n';
	return str;
}

unsigned CGumballMachine::GetBallsCount() const
{
	return m_ballsCount;
}

void CGumballMachine::ReleaseBall()
{
	if (m_ballsCount != 0)
	{
		m_strm << "A gumball comes rolling out the slot...\n";
		--m_ballsCount;
	}
}

unsigned CGumballMachine::GetQuartersCount() const
{
	return m_quartersCount;
}

void CGumballMachine::AddQuarter()
{
	m_strm << "You inserted a quarter\n";
	++m_quartersCount;
}

void CGumballMachine::RemoveOneQuarter()
{
	--m_quartersCount;
}

void CGumballMachine::RemoveAllQuarters()
{
	m_strm << "Quarters returned\n";
	m_quartersCount = 0;
}

void CGumballMachine::SetSoldOutState()
{
	m_currentState.reset(new CSoldOutState(*this, m_strm));
}

void CGumballMachine::SetNoQuarterState()
{
	m_currentState.reset(new CNoQuarterState(*this, m_strm));
}

void CGumballMachine::SetSoldState()
{
	m_currentState.reset(new CSoldState(*this, m_strm));
}

void CGumballMachine::SetHasQuarterState()
{
	m_currentState.reset(new CHasQuarterState(*this, m_strm));
}