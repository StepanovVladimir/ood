#pragma once

#include "CondimentDecorator.h"

class CCream : public CCondimentDecorator
{
public:
	CCream(IBeveragePtr &&beverage);

protected:
	std::string GetCondimentDescription() const override;
	double GetCondimentCost() const override;
};