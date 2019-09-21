#include "pch.h"
#include "Beverage.h"

CBeverage::CBeverage(const std::string &description)
	: m_description(description)
{
}

std::string CBeverage::GetDescription() const
{
	return m_description;
}