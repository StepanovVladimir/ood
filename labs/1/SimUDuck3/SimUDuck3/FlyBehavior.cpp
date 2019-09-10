#include "pch.h"
#include "FlyBehavior.h"
#include <iostream>

using namespace std;

std::function<void()> FlyWithWings()
{
	size_t flightsNumber = 0;

	return [flightsNumber]() mutable
	{
		flightsNumber++;
		cout << "Fly with wings " << flightsNumber << endl;
	};
}

std::function<void()> FlyRocketPowered()
{
	size_t flightsNumber = 0;

	return[flightsNumber]() mutable
	{
		flightsNumber++;
		cout << "Fly rocket powered " << flightsNumber << endl;
	};
}

std::function<void()> FlyNoWay()
{
	return []()
	{
		cout << "No fly\n";
	};
}
