#include "pch.h"
#include "CurrentConditionDisplay.h"
#include <iostream>

using namespace std;

void CCurrentConditionDisplay::Update(double value, EventType eventType)
{
	switch (eventType)
	{
	case EventType::Temperature:
		cout << "Current temperature: " << value << endl;
		break;

	case EventType::Humidity:
		cout << "Current humidity: " << value << endl;
		break;

	case EventType::Pressure:
		cout << "Current pressure: " << value << endl;
		break;

	case EventType::WindSpeed:
		cout << "Current wind speed: " << value << endl;
		break;

	case EventType::WindDirection:
		cout << "Current wind direction: " << value << endl;
		break;
	}
}