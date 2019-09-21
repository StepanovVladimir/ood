#pragma once

#include "Coffee.h"

class CLatte : public CCoffee
{
public:
	enum class Portion
	{
		Standart,
		Double
	};

	CLatte(Portion portion = Portion::Standart);
	
	double GetCost() const override;

private:
	Portion m_portion;
};