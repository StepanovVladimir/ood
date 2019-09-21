#pragma once

#include "Beverage.h"

class CMilkshake : public CBeverage
{
public:
	enum class Portion
	{
		Small,
		Medium,
		Large,
	};

	CMilkshake(Portion portion = Portion::Large);

	double GetCost() const override;

private:
	Portion m_portion;

	std::string PortionToString(Portion portion) const;
};

