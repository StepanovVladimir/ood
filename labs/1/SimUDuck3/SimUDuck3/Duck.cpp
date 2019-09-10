#include "pch.h"
#include "Duck.h"
#include <iostream>

using namespace std;

CDuck::CDuck(const std::function<void()> &quackBehavior, const std::function<void()> &flyBehavior,
	const std::function<void()> &danceBehavior)
	: m_quackBehavior(quackBehavior)
	, m_flyBehavior(flyBehavior)
	, m_danceBehavior(danceBehavior)
{
}

void CDuck::PerformQuack() const
{
	m_quackBehavior();
}

void CDuck::PerformFly()
{
	m_flyBehavior();
}

void CDuck::PerformDance() const
{
	m_danceBehavior();
}

void CDuck::PerformSwim() const
{
	cout << "Swim\n";
}

void CDuck::SetFlyBehavior(const std::function<void()> &flyBehavior)
{
	m_flightsNumber = 0;
	m_flyBehavior = flyBehavior;
}