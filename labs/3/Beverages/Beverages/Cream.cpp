#include "pch.h"
#include "Cream.h"

CCream::CCream(IBeveragePtr &&beverage)
	: CCondimentDecorator(move(beverage))
{
}

std::string CCream::GetCondimentDescription() const
{
	return "Cream";
}

double CCream::GetCondimentCost() const
{
	return 25;
}