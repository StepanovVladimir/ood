#include "pch.h"
#include "MallardDuck.h"
#include <iostream>

using namespace std;

CMallardDuck::CMallardDuck()
{
	m_quackBehavior = make_unique<QuackBehavior>(Quack);
	m_flyBehavior = make_unique<FlyBehavior>(FlyWithWings);
	m_danceBehavior = make_unique<DanceBehavior>(Waltz);
}

void CMallardDuck::Display() const
{
	cout << "Mallard duck\n";
}