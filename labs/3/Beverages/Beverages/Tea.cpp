#include "pch.h"
#include "Tea.h"

CTea::CTea(const std::string &description)
	: CBeverage(description)
{
}

double CTea::GetCost() const
{
	return 30;
}