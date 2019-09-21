#pragma once

#include "CondimentDecorator.h"

class CCinnamon : public CCondimentDecorator
{
public:
	CCinnamon(IBeveragePtr &&beverage);

protected:
	std::string GetCondimentDescription() const override;
	double GetCondimentCost() const override;
};