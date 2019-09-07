#pragma once

#include "QuackBehavior.h"
#include "FlyBehavior.h"
#include "DanceBehavior.h"
#include <memory>

class CDuck
{
public:
	virtual ~CDuck() = default;

	void PerformQuack() const;
	void PerformFly();
	void PerformDance() const;
	void Swim() const;

	void SetFlyBehavior(std::unique_ptr<FlyBehavior> flyBehavior);

	virtual void Display() const = 0;

protected:
	std::unique_ptr<QuackBehavior> m_quackBehavior;
	std::unique_ptr<FlyBehavior> m_flyBehavior;
	std::unique_ptr<DanceBehavior> m_danceBehavior;

private:
	size_t m_flightsNumber = 0;
};