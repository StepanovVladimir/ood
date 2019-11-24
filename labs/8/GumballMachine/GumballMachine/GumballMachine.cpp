#include "pch.h"
#include "GumballMachine.h"
#include "SoldOutState.h"
#include "NoQuarterState.h"
#include "SoldState.h"
#include "HasQuarterState.h"
#include <iostream>

using namespace std;

CGumballMachine::CGumballMachine(unsigned numBalls)
	: m_count(numBalls)
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

void CGumballMachine::EjectQuarter()
{
	m_currentState->EjectQuarter();
}

void CGumballMachine::InsertQuarter()
{
	m_currentState->InsertQuarter();
}

void CGumballMachine::TurnCrank()
{
	m_currentState->TurnCrank();
	m_currentState->Dispense();
}

string CGumballMachine::ToString() const
{
	string str = "\nMighty Gumball, Inc.\n";
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
		cout << "A gumball comes rolling out the slot...\n";
		--m_count;
	}
}

void CGumballMachine::SetSoldOutState()
{
	m_currentState.reset(new CSoldOutState(*this));
}

void CGumballMachine::SetNoQuarterState()
{
	m_currentState.reset(new CNoQuarterState(*this));
}

void CGumballMachine::SetSoldState()
{
	m_currentState.reset(new CSoldState(*this));
}

void CGumballMachine::SetHasQuarterState()
{
	m_currentState.reset(new CHasQuarterState(*this));
}