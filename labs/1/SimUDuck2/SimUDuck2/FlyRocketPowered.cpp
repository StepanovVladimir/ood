#include "pch.h"
#include "FlyRocketPowered.h"
#include <iostream>

void CFlyRocketPowered::Fly()
{
	m_flightsNumber++;
	std::cout << "Fly rocket powered " << m_flightsNumber << '\n';
}