#include "pch.h"
#include "DecoyDuck.h"
#include <iostream>

using namespace std;

CDecoyDuck::CDecoyDuck()
	: CDuck(
		make_unique<QuackBehavior>(MuteQuack),
		make_unique<FlyBehavior>(FlyNoWay),
		make_unique<DanceBehavior>(NoDance)
	)
{
}

void CDecoyDuck::Display() const
{
	cout << "Decoy duck\n";
}