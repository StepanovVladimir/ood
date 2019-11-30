#pragma once

#include "IState.h"
#include "IGumballMachine.h"
#include <iostream>

class CSoldOutState : public IState
{
public:
	CSoldOutState(IGumballMachine& gumballMachine, std::ostream& strm = std::cout);

	void InsertQuarter() override;
	void EjectQuarter() override;
	void TurnCrank() override;
	void Dispense() override;
	void Refill(unsigned numBalls) override;

	std::string ToString() const override;

private:
	IGumballMachine& m_gumballMachine;
	std::ostream& m_strm;
};