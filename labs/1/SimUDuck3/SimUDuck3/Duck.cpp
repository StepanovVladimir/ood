#include "pch.h"
#include "Duck.h"
#include <iostream>

using namespace std;

void CDuck::PerformQuack() const
{
	m_quackStrategy(*m_quackBehavior);
}

void CDuck::PerformFly() const
{
	m_flyStrategy(*m_flyBehavior);
}

void CDuck::PerformDance() const
{
	m_danceStrategy(*m_danceBehavior);
}

void CDuck::Swim() const
{
	cout << "Swim\n";
}

void CDuck::SetFlyBehavior(unique_ptr<IFlyBehavior> flyBehavior)
{
	m_flyBehavior = move(flyBehavior);
}