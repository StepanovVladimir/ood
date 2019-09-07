#include "pch.h"
#include "DecoyDuck.h"
#include <iostream>

using namespace std;

CDecoyDuck::CDecoyDuck()
{
	m_quackBehavior = make_unique<QuackBehavior>(MuteQuack);
	m_flyBehavior = make_unique<FlyBehavior>(FlyNoWay);
	m_danceBehavior = make_unique<DanceBehavior>(NoDance);
}

void CDecoyDuck::Display() const
{
	cout << "Decoy duck\n";
}