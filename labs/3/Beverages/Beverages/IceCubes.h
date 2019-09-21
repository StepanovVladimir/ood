#pragma once

#include "CondimentDecorator.h"

class CIceCubes : public CCondimentDecorator
{
public:
	enum class Type
	{
		Dry,
		Water
	};

	CIceCubes(IBeveragePtr &&beverage, unsigned quantity, Type type = Type::Water);

protected:
	std::string GetCondimentDescription() const override;
	double GetCondimentCost() const override;

private:
	unsigned m_quantity;
	Type m_type;
};