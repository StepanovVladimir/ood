#include "pch.h"
#include "RubberDuck.h"
#include <iostream>

using namespace std;

CRubberDuck::CRubberDuck()
{
	m_quackBehavior = make_unique<QuackBehavior>(Squeak);
	m_flyBehavior = make_unique<FlyBehavior>(FlyNoWay);
	m_danceBehavior = make_unique<DanceBehavior>(NoDance);
}

void CRubberDuck::Display() const
{
	cout << "Rubber duck\n";
}