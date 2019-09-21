#pragma once

#include "CondimentDecorator.h"

class CSyrup : public CCondimentDecorator
{
public:
	enum class Type
	{
		Chocolate,
		Maple
	};

	CSyrup(IBeveragePtr &&beverage, Type type);

protected:
	std::string GetCondimentDescription() const override;
	double GetCondimentCost() const override;

private:
	Type m_type;
};