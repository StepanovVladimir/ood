#include "pch.h"
#include "DecoyDuck.h"
#include "MuteQuack.h"
#include "FlyNoWay.h"
#include "NoDance.h"
#include <iostream>

using namespace std;

CDecoyDuck::CDecoyDuck()
{
	m_quackBehavior = make_unique<CMuteQuack>();
	m_flyBehavior = make_unique<CFlyNoWay>();
	m_danceBehavior = make_unique<CNoDance>();
}

void CDecoyDuck::Display() const
{
	cout << "Decoy duck\n";
}