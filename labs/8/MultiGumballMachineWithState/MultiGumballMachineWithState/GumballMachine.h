#pragma once

#include "IGumballMachine.h"
#include "IState.h"
#include <iostream>

class CGumballMachine : private IGumballMachine
{
public:
	CGumballMachine(unsigned numBalls = 0, std::ostream& strm = std::cout);

	void InsertQuarter();
	void EjectQuarter();
	void TurnCrank();
	void Refill(unsigned numBalls);

	std::string ToString() const;

private:
	unsigned GetBallsCount() const override;
	void ReleaseBall() override;
	void AddBalls(unsigned numBalls) override;

	unsigned GetQuartersCount() const override;
	void AddQuarter() override;
	void RemoveOneQuarter() override;
	void RemoveAllQuarters() override;

	void SetSoldOutState() override;
	void SetNoQuarterState() override;
	void SetSoldState() override;
	void SetHasQuarterState() override;

	unsigned m_quartersCount = 0;
	unsigned m_ballsCount;
	std::ostream& m_strm;
	std::unique_ptr<IState> m_currentState;
};