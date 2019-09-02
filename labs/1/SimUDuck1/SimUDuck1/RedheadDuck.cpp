#include "pch.h"
#include "RedheadDuck.h"
#include "Quack.h"
#include "FlyWithWings.h"
#include "Minuet.h"
#include <iostream>

using namespace std;

CRedheadDuck::CRedheadDuck()
{
	m_quackBehavior = make_unique<CQuack>();
	m_flyBehavior = make_unique<CFlyWithWings>();
	m_danceBehavior = make_unique<CMinuet>();
}

void CRedheadDuck::Display() const
{
	cout << "Redhead duck\n";
}