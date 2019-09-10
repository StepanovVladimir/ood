#include "pch.h"
#include "Duck.h"
#include <iostream>

using namespace std;

CDuck::CDuck(std::unique_ptr<IQuackBehavior> quackBehavior, std::unique_ptr<IFlyBehavior> flyBehavior,
	std::unique_ptr<IDanceBehavior> danceBehavior)
{
	m_quackBehavior = move(quackBehavior);
	m_flyBehavior = move(flyBehavior);
	m_danceBehavior = move(danceBehavior);
}

void CDuck::Quack() const
{
	m_quackBehavior->Quack();
}

void CDuck::Fly() const
{
	m_flyBehavior->Fly();
}

void CDuck::Dance() const
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