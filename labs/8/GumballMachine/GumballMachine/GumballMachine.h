#pragma once

#include "IGumballMachine.h"
#include "IState.h"
#include <iostream>

class CGumballMachine : private IGumballMachine
{
public:
	CGumballMachine(unsigned numBalls, std::ostream& strm = std::cout);

	void InsertQuarter();
	void EjectQuarter();
	void TurnCrank();
	std::string ToString() const;

private:
	unsigned GetBallCount() const override;
	void ReleaseBall() override;

	void SetSoldOutState() override;
	void SetNoQuarterState() override;
	void SetSoldState() override;
	void SetHasQuarterState() override;

	unsigned m_count;
	std::ostream& m_strm;
	std::unique_ptr<IState> m_currentState;
};