#pragma once

#include "Beverage.h"

class CCoffee : public CBeverage
{
public:
	CCoffee(const std::string &description = "Coffee");

	double GetCost() const override;
};