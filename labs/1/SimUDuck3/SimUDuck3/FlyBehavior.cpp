#include "pch.h"
#include "FlyBehavior.h"
#include <iostream>

using namespace std;

void FlyWithWings(size_t &flightsNumber)
{
	flightsNumber++;
	cout << "Fly with wings " << flightsNumber << endl;
}

void FlyRocketPowered(size_t &flightsNumber)
{
	flightsNumber++;
	cout << "Fly rocket powered " << flightsNumber << endl;
}

void FlyNoWay(size_t &flightsNumber)
{
	cout << endl;
}
