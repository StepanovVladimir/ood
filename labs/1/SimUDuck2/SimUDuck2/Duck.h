#pragma once

#include "IQuackBehavior.h"
#include "IFlyBehavior.h"
#include "IDanceBehavior.h"
#include <memory>

class CDuck
{
public:
	CDuck(std::unique_ptr<IQuackBehavior> quackBehavior, std::unique_ptr<IFlyBehavior> flyBehavior,
		std::unique_ptr<IDanceBehavior> m_danceBehavior);

	virtual ~CDuck() = default;

	void Quack() const;
	void Fly() const;
	void Dance() const;
	void Swim() const;

	void SetFlyBehavior(std::unique_ptr<IFlyBehavior> flyBehavior);

	virtual void Display() const = 0;

private:
	std::unique_ptr<IQuackBehavior> m_quackBehavior;
	std::unique_ptr<IFlyBehavior> m_flyBehavior;
	std::unique_ptr<IDanceBehavior> m_danceBehavior;
};