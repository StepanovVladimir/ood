#include "pch.h"
#include "Duck.h"
#include <iostream>

using namespace std;

void CDuck::PerformQuack() const
{
	m_quackBehavior->Quack();
}

void CDuck::PerformFly() const
{
	m_flyBehavior->Fly();
}

void CDuck::PerformDance() const
{
	m_danceBehavior->Dance();
}

void CDuck::Swim() const
{
	cout << "Swim\n";
}

void CDuck::SetFlyBehavior(unique_ptr<IFlyBehavior> flyBehavior)
{
	m_flyBehavior = move(flyBehavior);
}