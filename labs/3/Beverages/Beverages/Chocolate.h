#pragma once

#include "CondimentDecorator.h"

class CChocolate : public CCondimentDecorator
{
public:
	static const unsigned MAX_QUANTITY = 5;

	CChocolate(IBeveragePtr &&beverage, unsigned quantity = 1);

protected:
	std::string GetCondimentDescription() const override;
	double GetCondimentCost() const override;

private:
	unsigned m_quantity;
};
