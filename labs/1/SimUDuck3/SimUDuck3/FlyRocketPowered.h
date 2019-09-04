#pragma once

#include "IFlyBehavior.h"

class CFlyRocketPowered : public IFlyBehavior
{
public:
	void Fly() override;

private:
	size_t m_flightsNumber = 0;
};

