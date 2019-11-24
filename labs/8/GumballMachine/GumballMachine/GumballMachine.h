#pragma once

#include "IGumballMachine.h"
#include "IState.h"
#include <string>

class CGumballMachine : private IGumballMachine
{
public:
	CGumballMachine(unsigned numBalls);

	void EjectQuarter();
	void InsertQuarter();
	void TurnCrank();
	std::string ToString() const;

private:
	unsigned GetBallCount() const override;
	void ReleaseBall() override;

	void SetSoldOutState() override;
	void SetNoQuarterState() override;
	void SetSoldState() override;
	void SetHasQuarterState() override;

	unsigned m_count = 0;
	std::unique_ptr<IState> m_currentState;
};