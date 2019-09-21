#pragma once

#include "IBeverage.h"

class CCondimentDecorator : public IBeverage
{
public:
	std::string GetDescription() const override;
	double GetCost() const override;

protected:
	CCondimentDecorator(IBeveragePtr &&beverage);

	virtual std::string GetCondimentDescription() const = 0;
	virtual double GetCondimentCost() const = 0;

private:
	IBeveragePtr m_beverage;
};