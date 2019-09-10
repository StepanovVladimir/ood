#include "pch.h"
#include "MallardDuck.h"
#include "Quack.h"
#include "FlyWithWings.h"
#include "Waltz.h"
#include <iostream>

using namespace std;

CMallardDuck::CMallardDuck()
	: CDuck(
		make_unique<CQuack>(), 
		make_unique<CFlyWithWings>(), 
		make_unique<CWaltz>()
	)
{
}

void CMallardDuck::Display() const
{
	cout << "Mallard duck\n";
}