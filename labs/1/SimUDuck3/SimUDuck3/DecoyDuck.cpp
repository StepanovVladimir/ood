#include "pch.h"
#include "DecoyDuck.h"
#include <iostream>

using namespace std;

CDecoyDuck::CDecoyDuck()
	: CDuck(MuteQuack, FlyNoWay(), NoDance)
{
}

void CDecoyDuck::Display() const
{
	cout << "Decoy duck\n";
}