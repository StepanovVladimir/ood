#include "pch.h"
#include "Cinnamon.h"

CCinnamon::CCinnamon(IBeveragePtr &&beverage)
	: CCondimentDecorator(move(beverage))
{
}

std::string CCinnamon::GetCondimentDescription() const
{
	return "Cinnamon";
}

double CCinnamon::GetCondimentCost() const
{
	return 20;
}