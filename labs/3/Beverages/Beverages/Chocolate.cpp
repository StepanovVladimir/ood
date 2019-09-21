#include "pch.h"
#include "Chocolate.h"
#include <algorithm>

CChocolate::CChocolate(IBeveragePtr &&beverage, unsigned quantity)
	: CCondimentDecorator(move(beverage))
	, m_quantity(std::min(quantity, MAX_QUANTITY))
{
}

std::string CChocolate::GetCondimentDescription() const
{
	return "Chocolate x " + std::to_string(m_quantity);
}

double CChocolate::GetCondimentCost() const
{
	return 10 * m_quantity;
}