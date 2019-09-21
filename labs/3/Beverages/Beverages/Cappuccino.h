#pragma once

#include "Coffee.h"

class CCappuccino : public CCoffee
{
public:
	enum class Portion
	{
		Standart,
		Double
	};

	CCappuccino(Portion portion = Portion::Standart);

	double GetCost() const override;

private:
	Portion m_portion;
};