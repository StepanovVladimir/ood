#include "pch.h"
#include "GumballMachine.h"
#include "SoldOutState.h"
#include "NoQuarterState.h"
#include "SoldState.h"
#include "HasQuarterState.h"

using namespace std;

CGumballMachine::CGumballMachine(unsigned numBalls, ostream& strm)
	: m_count(numBalls)
	, m_strm(strm)
{
	if (m_count > 0)
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
	str += "Inventory: " + to_string(m_count) + " gumball" + (m_count != 1 ? "s" : "") + '\n';
	str += "Machine is " + m_currentState->ToString() + '\n';
	return str;
}

unsigned CGumballMachine::GetBallCount() const
{
	return m_count;
}

void CGumballMachine::ReleaseBall()
{
	if (m_count != 0)
	{
		m_strm << "A gumball comes rolling out the slot...\n";
		--m_count;
	}
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