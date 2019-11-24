#pragma once

#include <string>

class IState
{
public:
	virtual ~IState() = default;

	virtual void InsertQuarter() = 0;
	virtual void EjectQuarter() = 0;
	virtual void TurnCrank() = 0;
	virtual void Dispense() = 0;

	virtual std::string ToString() const = 0;
};