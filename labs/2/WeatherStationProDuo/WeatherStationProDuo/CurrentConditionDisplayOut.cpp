#include "pch.h"
#include "CurrentConditionDisplayOut.h"
#include <iostream>

using namespace std;

void CCurrentConditionDisplayOut::Update(const WeatherInfoOut &weatherInfo)
{
	cout << "Current condition without:\n";
	cout << "  temperature: " << weatherInfo.temperature << endl;
	cout << "  humidity: " << weatherInfo.humidity << endl;
	cout << "  pressure: " << weatherInfo.pressure << endl;
	cout << "  wind speed: " << weatherInfo.windSpeed << endl;
	cout << "  wind direction: " << weatherInfo.windDirection << endl;
}