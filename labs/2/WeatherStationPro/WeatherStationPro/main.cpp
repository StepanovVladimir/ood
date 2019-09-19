#include "pch.h"
#include "WeatherData.h"
#include "CurrentConditionDisplay.h"
#include "StatisticsDisplay.h"
#include <iostream>

using namespace std;

int main()
{
	CWeatherData weatherData;

	CCurrentConditionDisplay display;
	weatherData.RegisterObserver(display, 0, EventType::Temperature);
	weatherData.RegisterObserver(display, 0, EventType::Pressure);

	CStatisticsDisplay statsDisplay;
	weatherData.RegisterObserver(statsDisplay, 1, EventType::WindDirection);

	weatherData.SetData({ 3, 70, 760, 5, 180 });
	weatherData.SetData({ 4, 80, 760, 4, 270 });
	cout << "----------------\n";

	weatherData.RemoveObserver(display);

	weatherData.SetData({ 10, 80, 761, 6, 180 });
	weatherData.SetData({ -10, 80, 761, 5, 100 });

	return 0;
}