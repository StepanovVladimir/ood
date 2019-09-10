#pragma once

#include "QuackBehavior.h"
#include "FlyBehavior.h"
#include "DanceBehavior.h"
#include <memory>

class CDuck
{
public:
	CDuck(std::unique_ptr<QuackBehavior> quackBehavior, std::unique_ptr<FlyBehavior> flyBehavior,
		std::unique_ptr<DanceBehavior> danceBehavior);

	virtual ~CDuck() = default;

	void PerformQuack() const;
	void PerformFly();
	void PerformDance() const;
	void PerformSwim() const;

	void SetFlyBehavior(std::unique_ptr<FlyBehavior> flyBehavior);

	virtual void Display() const = 0;

private:
	std::unique_ptr<QuackBehavior> m_quackBehavior;
	std::unique_ptr<FlyBehavior> m_flyBehavior;
	std::unique_ptr<DanceBehavior> m_danceBehavior;

	size_t m_flightsNumber = 0;
};