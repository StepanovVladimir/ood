#pragma once

#include "IBeverage.h"

class CBeverage : public IBeverage
{
public:
	CBeverage(const std::string &description);
	
	std::string GetDescription() const override final;

private:
	std::string m_description;
};