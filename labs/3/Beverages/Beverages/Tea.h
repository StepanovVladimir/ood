#pragma once

#include "Beverage.h"

class CTea : public CBeverage
{
public:
	CTea(const std::string &description = "Tea");
	
	double GetCost() const override;
};