#include "pch.h"
#include "CoconutFlakes.h"

CCoconutFlakes::CCoconutFlakes(IBeveragePtr &&beverage, unsigned mass)
	: CCondimentDecorator(move(beverage))
	, m_mass(mass)
{
}

std::string CCoconutFlakes::GetCondimentDescription() const
{
	return "Coconut flakes " + std::to_string(m_mass) + "g";
}

double CCoconutFlakes::GetCondimentCost() const
{
	return 1 * m_mass;
}