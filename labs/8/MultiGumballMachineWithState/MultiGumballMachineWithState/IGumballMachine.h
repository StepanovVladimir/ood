#pragma once

class IGumballMachine
{
public:
	virtual ~IGumballMachine() = default;

	virtual unsigned GetBallsCount() const = 0;
	virtual void ReleaseBall() = 0;

	virtual unsigned GetQuartersCount() const = 0;
	virtual void AddQuarter() = 0;
	virtual void RemoveOneQuarter() = 0;
	virtual void RemoveAllQuarters() = 0;

	virtual void SetSoldOutState() = 0;
	virtual void SetNoQuarterState() = 0;
	virtual void SetSoldState() = 0;
	virtual void SetHasQuarterState() = 0;
};