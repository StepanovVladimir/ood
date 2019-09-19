#include "pch.h"
#include "CurrentConditionDisplayIn.h"
#include <iostream>

using namespace std;

void CCurrentConditionDisplayIn::Update(const WeatherInfoIn &weatherInfo)
{
	cout << "Current condition indoors:\n";
	cout << "  temperature: " << weatherInfo.temperature << endl;
	cout << "  humidity: " << weatherInfo.humidity << endl;
	cout << "  pressure: " << weatherInfo.pressure << endl;
}