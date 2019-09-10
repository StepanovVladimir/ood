#include "pch.h"
#include "MallardDuck.h"
#include <iostream>

using namespace std;

CMallardDuck::CMallardDuck()
	: CDuck(Quack, FlyWithWings(), Waltz)
{
}

void CMallardDuck::Display() const
{
	cout << "Mallard duck\n";
}