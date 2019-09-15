#include "pch.h"
#include "CurrentConditionDisplay.h"
#include <iostream>

using namespace std;

void CCurrentConditionDisplay::Update(const WeatherInfo &weatherInfo, ObservableType observableType)
{
	if (observableType == ObservableType::In)
	{
		cout << "Current condition indoors:\n";
	}
	else
	{
		cout << "Current condition out:\n";
	}
	cout << "  temperature: " << weatherInfo.temperature << endl;
	cout << "  humidity: " << weatherInfo.humidity << endl;
	cout << "  pressure: " << weatherInfo.pressure << endl;
}