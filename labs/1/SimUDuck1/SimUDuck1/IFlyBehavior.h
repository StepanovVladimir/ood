#pragma once

class IFlyBehavior
{
public:
	virtual ~IFlyBehavior() = default;

	virtual void Fly() const = 0;
};