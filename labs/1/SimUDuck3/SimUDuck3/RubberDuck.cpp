#include "pch.h"
#include "RubberDuck.h"
#include <iostream>

using namespace std;

CRubberDuck::CRubberDuck()
	: CDuck(
		make_unique<QuackBehavior>(Squeak),
		make_unique<FlyBehavior>(FlyNoWay),
		make_unique<DanceBehavior>(NoDance)
	)
{
}

void CRubberDuck::Display() const
{
	cout << "Rubber duck\n";
}