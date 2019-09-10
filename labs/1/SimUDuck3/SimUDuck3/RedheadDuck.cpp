#include "pch.h"
#include "RedheadDuck.h"
#include <iostream>

using namespace std;

CRedheadDuck::CRedheadDuck()
	: CDuck(Quack, FlyWithWings(), Minuet)
{
}

void CRedheadDuck::Display() const
{
	cout << "Redhead duck\n";
}