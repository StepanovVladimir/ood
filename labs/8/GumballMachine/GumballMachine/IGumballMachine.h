#pragma once

class IGumballMachine
{
public:
	virtual ~IGumballMachine() = default;

	virtual unsigned GetBallCount() const = 0;
	virtual void ReleaseBall() = 0;

	virtual void SetSoldOutState() = 0;
	virtual void SetNoQuarterState() = 0;
	virtual void SetSoldState() = 0;
	virtual void SetHasQuarterState() = 0;
};