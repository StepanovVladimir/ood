#pragma once

#include "CondimentDecorator.h"

class CLiquor : public CCondimentDecorator
{
public:
	enum class Type
	{
		Walnut,
		Chocolate
	};

	CLiquor(IBeveragePtr &&beverage, Type type);

protected:
	std::string GetCondimentDescription() const override;
	double GetCondimentCost() const override;

private:
	Type m_type;
};

