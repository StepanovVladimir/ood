#include "pch.h"
#include "IceCubes.h"

CIceCubes::CIceCubes(IBeveragePtr &&beverage, unsigned quantity, Type type)
	: CCondimentDecorator(move(beverage))
	, m_quantity(quantity)
	, m_type(type)
{
}

std::string CIceCubes::GetCondimentDescription() const
{
	return std::string(m_type == Type::Dry ? "Dry" : "Water")
		+ " ice cubes x " + std::to_string(m_quantity);
}

double CIceCubes::GetCondimentCost() const
{
	return (m_type == Type::Dry ? 10 : 5) * m_quantity;
}