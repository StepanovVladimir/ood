#include "pch.h"
#include "Liquor.h"

CLiquor::CLiquor(IBeveragePtr &&beverage, Type type)
	: CCondimentDecorator(move(beverage))
	, m_type(type)
{
}

std::string CLiquor::GetCondimentDescription() const
{
	return std::string(m_type == Type::Walnut ? "Walnut" : "Chocolate")
		+ " liquor";
}

double CLiquor::GetCondimentCost() const
{
	return 50;
}