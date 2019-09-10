#include "pch.h"
#include "MallardDuck.h"
#include <iostream>

using namespace std;

CMallardDuck::CMallardDuck()
	: CDuck(
		make_unique<QuackBehavior>(Quack),
		make_unique<FlyBehavior>(FlyWithWings),
		make_unique<DanceBehavior>(Waltz)
	)
{
}

void CMallardDuck::Display() const
{
	cout << "Mallard duck\n";
}