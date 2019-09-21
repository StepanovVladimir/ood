#include "pch.h"
#include "CondimentDecorator.h"

CCondimentDecorator::CCondimentDecorator(IBeveragePtr &&beverage)
	: m_beverage(move(beverage))
{
}

std::string CCondimentDecorator::GetDescription() const
{
	return m_beverage->GetDescription() + ", " + GetCondimentDescription();
}

double CCondimentDecorator::GetCost() const
{
	return m_beverage->GetCost() + GetCondimentCost();
}