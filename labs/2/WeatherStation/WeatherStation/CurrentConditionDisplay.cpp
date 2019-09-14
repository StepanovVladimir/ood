#include "pch.h"
#include "CurrentConditionDisplay.h"
#include <iostream>

using namespace std;

void CCurrentConditionDisplay::Update(const WeatherInfo &weatherInfo)
{
	cout << "Current condition:\n";
	cout << "  temperature: " << weatherInfo.temperature << endl;
	cout << "  humidity: " << weatherInfo.humidity << endl;
	cout << "  pressure: " << weatherInfo.pressure << endl;
}