#include "pch.h"
#include "Milkshake.h"

CMilkshake::CMilkshake(Portion portion)
	: CBeverage(PortionToString(portion) + " milkshake")
	, m_portion(portion)
{
}

double CMilkshake::GetCost() const
{
	switch (m_portion)
	{
	case Portion::Small:
		return 50;

	case Portion::Medium:
		return 60;

	default:
		return 80;
	}
}

std::string CMilkshake::PortionToString(Portion portion) const
{
	switch (portion)
	{
	case Portion::Small:
		return "Small";

	case Portion::Medium:
		return "Medium";

	default:
		return "Large";
	}
}