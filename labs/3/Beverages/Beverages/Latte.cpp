#include "pch.h"
#include "Latte.h"

CLatte::CLatte(Portion portion)
	: CCoffee(portion == Portion::Standart ? "Latte" : "Double latte")
	, m_portion(portion)
{
}

double CLatte::GetCost() const
{
	if (m_portion == Portion::Double)
	{
		return 130;
	}
	return 90;
}