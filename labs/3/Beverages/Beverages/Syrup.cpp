#include "pch.h"
#include "Syrup.h"

CSyrup::CSyrup(IBeveragePtr &&beverage, Type type)
	: CCondimentDecorator(move(beverage))
	, m_type(type)
{
}

std::string CSyrup::GetCondimentDescription() const
{
	return std::string(m_type == Type::Chocolate ? "Chocolate" : "Maple")
		+ " syrup";
}

double CSyrup::GetCondimentCost() const
{
	return 15;
}