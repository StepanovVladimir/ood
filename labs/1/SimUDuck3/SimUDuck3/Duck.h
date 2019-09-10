#pragma once

#include "QuackBehavior.h"
#include "FlyBehavior.h"
#include "DanceBehavior.h"
#include <memory>

class CDuck
{
public:
	CDuck(const std::function<void()> &quackBehavior, const std::function<void()> &flyBehavior,
		const std::function<void()> &danceBehavior);

	virtual ~CDuck() = default;

	void PerformQuack() const;
	void PerformFly();
	void PerformDance() const;
	void PerformSwim() const;

	void SetFlyBehavior(const std::function<void()> &flyBehavior);

	virtual void Display() const = 0;

private:
	std::function<void()> m_quackBehavior;
	std::function<void()> m_flyBehavior;
	std::function<void()> m_danceBehavior;

	size_t m_flightsNumber = 0;
};