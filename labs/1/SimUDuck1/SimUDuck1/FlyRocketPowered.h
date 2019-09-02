#pragma once

#include "IFlyBehavior.h"

class CFlyRocketPowered : public IFlyBehavior
{
public:
	void Fly() const override;
};

