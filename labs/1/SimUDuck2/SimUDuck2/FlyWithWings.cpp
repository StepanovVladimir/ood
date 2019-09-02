#include "pch.h"
#include "FlyWithWings.h"
#include <iostream>

void CFlyWithWings::Fly()
{
	m_flightsNumber++;
	std::cout << "Fly with wings " << m_flightsNumber << std::endl;
}