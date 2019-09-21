#include "pch.h"
#include "Cappuccino.h"

CCappuccino::CCappuccino(Portion portion)
	: CCoffee(portion == Portion::Standart ? "Cappuccino" : "Double cappuccino")
{
}

double CCappuccino::GetCost() const
{
	if (m_portion == Portion::Double)
	{
		return 120;
	}
	return 80;
}