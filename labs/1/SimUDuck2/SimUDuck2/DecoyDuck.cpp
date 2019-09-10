#include "pch.h"
#include "DecoyDuck.h"
#include "MuteQuack.h"
#include "FlyNoWay.h"
#include "NoDance.h"
#include <iostream>

using namespace std;

CDecoyDuck::CDecoyDuck()
	: CDuck(
		make_unique<CMuteQuack>(), 
		make_unique<CFlyNoWay>(), 
		make_unique<CNoDance>()
	)
{
}

void CDecoyDuck::Display() const
{
	cout << "Decoy duck\n";
}