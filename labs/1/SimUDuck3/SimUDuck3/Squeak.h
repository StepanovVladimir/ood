#pragma once

#include "IQuackBehavior.h"

class CSqueak : public IQuackBehavior
{
public:
	void Quack() const override;
};

