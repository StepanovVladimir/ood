#include "pch.h"
#include "Duck.h"
#include <iostream>

using namespace std;

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

void CDuck::Swim() const
{
	cout << "Swim\n";
}

void CDuck::SetFlyBehavior(unique_ptr<FlyBehavior> flyBehavior)
{
	m_flightsNumber = 0;
	m_flyBehavior = move(flyBehavior);
}