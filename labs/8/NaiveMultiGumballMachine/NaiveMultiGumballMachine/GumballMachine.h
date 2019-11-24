#pragma once

#include <iostream>
#include <string>

class CGumballMachine
{
public:
	enum class State
	{
		SoldOut,
		NoQuarter,
		HasQuarter,
		Sold
	};

	CGumballMachine(unsigned ballsCount, std::ostream& strm = std::cout);

	void InsertQuarter();
	void EjectQuarter();
	void TurnCrank();
	std::string ToString() const;

private:
	void Dispense();

	unsigned m_quartersCount = 0;
	unsigned m_ballsCount;
	State m_state;
	std::ostream& m_strm;
};