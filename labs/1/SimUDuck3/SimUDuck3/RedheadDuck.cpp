#include "pch.h"
#include "RedheadDuck.h"
#include <iostream>

using namespace std;

CRedheadDuck::CRedheadDuck()
{
	m_quackBehavior = make_unique<QuackBehavior>(Quack);
	m_flyBehavior = make_unique<FlyBehavior>(FlyWithWings);
	m_danceBehavior = make_unique<DanceBehavior>(Minuet);
}

void CRedheadDuck::Display() const
{
	cout << "Redhead duck\n";
}