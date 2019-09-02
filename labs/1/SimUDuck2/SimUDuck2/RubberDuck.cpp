#include "pch.h"
#include "RubberDuck.h"
#include "Squeak.h"
#include "FlyNoWay.h"
#include "NoDance.h"
#include <iostream>

using namespace std;

CRubberDuck::CRubberDuck()
{
	m_quackBehavior = make_unique<CSqueak>();
	m_flyBehavior = make_unique<CFlyNoWay>();
	m_danceBehavior = make_unique<CNoDance>();
}

void CRubberDuck::Display() const
{
	cout << "Rubber duck\n";
}