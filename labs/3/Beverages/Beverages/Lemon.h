#pragma once

#include "CondimentDecorator.h"

class CLemon : public CCondimentDecorator
{
public:
	CLemon(IBeveragePtr &&beverage, unsigned quantity = 1);

protected:
	std::string GetCondimentDescription() const override;
	double GetCondimentCost() const override;

private:
	unsigned m_quantity;
};