#include "pch.h"
#include "MallardDuck.h"
#include "Quack.h"
#include "FlyWithWings.h"
#include "Waltz.h"
#include <iostream>

using namespace std;

CMallardDuck::CMallardDuck()
{
	m_quackBehavior = make_unique<CQuack>();
	m_flyBehavior = make_unique<CFlyWithWings>();
	m_danceBehavior = make_unique<CWaltz>();
}

void CMallardDuck::Display() const
{
	cout << "Mallard duck\n";
}