#include "pch.h"
#include "WeatherData.h"
#include "CurrentConditionDisplay.h"
#include "StatisticsDisplay.h"
#include <iostream>

using namespace std;

int main()
{
	CWeatherData weatherData1;
	CWeatherData weatherData2;

	CCurrentConditionDisplay display;
	weatherData1.RegisterObserver(display, 0);
	weatherData2.RegisterObserver(display, 1);

	CStatisticsDisplay statsDisplay;
	weatherData1.RegisterObserver(statsDisplay, 1);
	weatherData2.RegisterObserver(statsDisplay, 0);

	weatherData1.SetData({ 3, 70, 760 });
	weatherData2.SetData({ 4, 80, 761 });
	cout << "----------------\n";

	weatherData2.RemoveObserver(statsDisplay);

	weatherData1.SetData({ 10, 80, 761 });
	weatherData2.SetData({ -10, 80, 761 });
	cout << "----------------\n";

	return 0;
}