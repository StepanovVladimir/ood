#include "pch.h"
#include "WeatherData.h"
#include "CurrentConditionDisplay.h"
#include "StatisticsDisplay.h"
#include <iostream>

using namespace std;

int main()
{
	CWeatherData weatherDataIn(ObservableType::In);
	CWeatherData weatherDataOut(ObservableType::Out);

	CCurrentConditionDisplay display;
	display.RegisterOnObservable(weatherDataIn, 0);
	display.RegisterOnObservable(weatherDataOut, 1);

	CStatisticsDisplay statsDisplay;
	statsDisplay.RegisterOnObservable(weatherDataIn, 1);
	statsDisplay.RegisterOnObservable(weatherDataOut, 0);

	weatherDataIn.SetData({ 3, 70, 760 });
	weatherDataOut.SetData({ 4, 80, 761 });
	cout << "----------------\n";

	statsDisplay.RemoveFromOutObservable();

	weatherDataIn.SetData({ 10, 80, 761 });
	weatherDataOut.SetData({ -10, 80, 761 });

	return 0;
}