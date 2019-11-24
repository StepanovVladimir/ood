#pragma once

#include "IState.h"
#include "IGumballMachine.h"
#include <iostream>

class CSoldState : public IState
{
public:
	CSoldState(IGumballMachine& gumballMachine, std::ostream& strm = std::cout);

	void InsertQuarter() override;
	void EjectQuarter() override;
	void TurnCrank() override;
	void Dispense() override;

	std::string ToString() const override;

private:
	IGumballMachine& m_gumballMachine;
	std::ostream& m_strm;
};