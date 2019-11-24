#include "pch.h"
#include "GumballMachine.h"

using namespace std;

CGumballMachine::CGumballMachine(unsigned ballsCount, ostream& strm)
	: m_ballsCount(ballsCount)
	, m_state(m_ballsCount > 0 ? State::NoQuarter : State::SoldOut)
	, m_strm(strm)
{
}

void CGumballMachine::InsertQuarter()
{
	switch (m_state)
	{
	case State::SoldOut:
		cout << "You can't insert a quarter, the machine is sold out\n";
		break;

	case State::NoQuarter:
		cout << "You inserted a quarter\n";
		++m_quartersCount;
		m_state = State::HasQuarter;
		break;

	case State::HasQuarter:
		if (m_quartersCount < 5)
		{
			cout << "You inserted a quarter\n";
			++m_quartersCount;
		}
		else
		{
			cout << "You can't insert more than 5 quarters\n";
		}
		break;

	case State::Sold:
		cout << "Please wait, we're already giving you a gumball\n";
		break;
	}
}

void CGumballMachine::EjectQuarter()
{
	switch (m_state)
	{
	case State::HasQuarter:
		cout << "Quarters returned\n";
		m_quartersCount = 0;
		m_state = State::NoQuarter;
		break;

	case State::NoQuarter:
		cout << "You haven't inserted a quarter\n";
		break;

	case State::Sold:
		cout << "Sorry you already turned the crank\n";
		break;

	case State::SoldOut:
		if (m_quartersCount > 0)
		{
			cout << "Quarters returned\n";
			m_quartersCount = 0;
		}
		else
		{
			cout << "You can't eject, you haven't inserted a quarter yet\n";
		}
		break;
	}
}

void CGumballMachine::TurnCrank()
{
	switch (m_state)
	{
	case State::SoldOut:
		cout << "You turned but there's no gumballs\n";
		break;

	case State::NoQuarter:
		cout << "You turned but there's no quarter\n";
		break;

	case State::HasQuarter:
		cout << "You turned...\n";
		--m_quartersCount;
		m_state = State::Sold;
		Dispense();
		break;

	case State::Sold:
		cout << "Turning twice doesn't get you another gumball\n";
		break;
	}
}

string CGumballMachine::ToString() const
{
	string state = (m_state == State::SoldOut) ? "sold out" :
		(m_state == State::NoQuarter) ? "waiting for quarter" :
		(m_state == State::HasQuarter) ? "waiting for turn of crank"
		: "delivering a gumball";

	string str = "Mighty Gumball, Inc.\n";
	str += "C++-enabled Standing Gumball Model #2016 (with state)\n";
	str += "Inventory: " + to_string(m_ballsCount) + " gumball" + (m_ballsCount != 1 ? "s, " : ", ");
	str += to_string(m_quartersCount) + " quarter" + (m_ballsCount != 1 ? "s\n" : "\n");
	str += "Machine is " + state + '\n';
	return str;
}

void CGumballMachine::Dispense()
{
	switch (m_state)
	{
	case State::Sold:
		cout << "A gumball comes rolling out the slot\n";
		--m_ballsCount;
		if (m_ballsCount == 0)
		{
			cout << "Oops, out of gumballs\n";
			m_state = State::SoldOut;
		}
		else if (m_quartersCount > 0)
		{
			m_state = State::HasQuarter;
		}
		else
		{
			m_state = State::NoQuarter;
		}
		break;

	case State::NoQuarter:
		cout << "You need to pay first\n";
		break;

	case State::SoldOut:

	case State::HasQuarter:
		cout << "No gumball dispensed\n";
		break;
	}
}