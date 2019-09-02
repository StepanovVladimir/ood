#pragma once

#include "IQuackBehavior.h"
#include "IFlyBehavior.h"
#include "IDanceBehavior.h"
#include <memory>

class CDuck
{
public:
	virtual ~CDuck() = default;

	void PerformQuack() const;
	void PerformFly() const;
	void PerformDance() const;
	void Swim() const;

	void SetFlyBehavior(std::unique_ptr<IFlyBehavior> flyBehavior);

	virtual void Display() const = 0;

protected:
	std::unique_ptr<IQuackBehavior> m_quackBehavior;
	std::unique_ptr<IFlyBehavior> m_flyBehavior;
	std::unique_ptr<IDanceBehavior> m_danceBehavior;
};