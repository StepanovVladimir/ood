#include "pch.h"
#include "RedheadDuck.h"
#include "Quack.h"
#include "FlyWithWings.h"
#include "Minuet.h"
#include <iostream>

using namespace std;

CRedheadDuck::CRedheadDuck()
	: CDuck(
		make_unique<CQuack>(), 
		make_unique<CFlyWithWings>(), 
		make_unique<CMinuet>()
	)
{
}

void CRedheadDuck::Display() const
{
	cout << "Redhead duck\n";
}