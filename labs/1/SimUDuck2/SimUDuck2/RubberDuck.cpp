#include "pch.h"
#include "RubberDuck.h"
#include "Squeak.h"
#include "FlyNoWay.h"
#include "NoDance.h"
#include <iostream>

using namespace std;

CRubberDuck::CRubberDuck()
	: CDuck(
		make_unique<CSqueak>(), 
		make_unique<CFlyNoWay>(), 
		make_unique<CNoDance>()
	)
{
}

void CRubberDuck::Display() const
{
	cout << "Rubber duck\n";
}