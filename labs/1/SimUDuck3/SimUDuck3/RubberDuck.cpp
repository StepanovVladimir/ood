#include "pch.h"
#include "RubberDuck.h"
#include <iostream>

using namespace std;

CRubberDuck::CRubberDuck()
	: CDuck(Squeak, FlyNoWay(), NoDance)
{
}

void CRubberDuck::Display() const
{
	cout << "Rubber duck\n";
}