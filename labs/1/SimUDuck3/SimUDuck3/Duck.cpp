#include "pch.h"
#include "Duck.h"
#include <iostream>

using namespace std;

CDuck::CDuck(std::unique_ptr<QuackBehavior> quackBehavior, std::unique_ptr<FlyBehavior> flyBehavior,
	std::unique_ptr<DanceBehavior> danceBehavior)
{
	m_quackBehavior = move(quackBehavior);
	m_flyBehavior = move(flyBehavior);
	m_danceBehavior = move(danceBehavior);
}

void CDuck::PerformQuack() const
{
	(*m_quackBehavior)();
}

void CDuck::PerformFly()
{
	(*m_flyBehavior)(m_flightsNumber);
}

void CDuck::PerformDance() const
{
	(*m_danceBehavior)();
}

void CDuck::PerformSwim() const
{
	cout << "Swim\n";
}

void CDuck::SetFlyBehavior(unique_ptr<FlyBehavior> flyBehavior)
{
	m_flightsNumber = 0;
	m_flyBehavior = move(flyBehavior);
}