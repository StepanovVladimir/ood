#include "pch.h"
#include "RedheadDuck.h"
#include <iostream>

using namespace std;

CRedheadDuck::CRedheadDuck()
	: CDuck(
		make_unique<QuackBehavior>(Quack),
		make_unique<FlyBehavior>(FlyWithWings),
		make_unique<DanceBehavior>(Minuet)
	)
{
}

void CRedheadDuck::Display() const
{
	cout << "Redhead duck\n";
}