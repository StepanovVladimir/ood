#include "pch.h"
#include "WeatherDataIn.h"
#include "WeatherDataOut.h"
#include "CurrentConditionDisplayIn.h"
#include "CurrentConditionDisplayOut.h"
#include "StatisticsDisplayIn.h"
#include "StatisticsDisplayOut.h"
#include <iostream>

using namespace std;

int main()
{
	CWeatherDataIn weatherDataIn;
	CWeatherDataOut weatherDataOut;

	CCurrentConditionDisplayIn displayIn;
	CCurrentConditionDisplayOut displayOut;
	weatherDataIn.RegisterObserver(displayIn, 0);
	weatherDataOut.RegisterObserver(displayOut, 1);

	CStatisticsDisplayIn statsDisplayIn;
	CStatisticsDisplayOut statsDisplayOut;
	weatherDataIn.RegisterObserver(statsDisplayIn, 1);
	weatherDataOut.RegisterObserver(statsDisplayOut, 0);

	weatherDataIn.SetData({ 3, 70, 760 });
	weatherDataOut.SetData({ 4, 80, 761, 4, 12 });
	cout << "----------------\n";

	weatherDataOut.RemoveObserver(statsDisplayOut);

	weatherDataIn.SetData({ 10, 80, 761 });
	weatherDataOut.SetData({ -10, 80, 761, 5, 60 });

	return 0;
}