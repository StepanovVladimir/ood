#include "pch.h"
#include "Coffee.h"

CCoffee::CCoffee(const std::string &description)
	: CBeverage(description)
{
}

double CCoffee::GetCost() const
{
	return 60;
}