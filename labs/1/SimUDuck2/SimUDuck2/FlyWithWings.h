#pragma once

#include "IFlyBehavior.h"

class CFlyWithWings : public IFlyBehavior
{
public:
	void Fly() override;

private:
	size_t m_flightsNumber = 0;
};