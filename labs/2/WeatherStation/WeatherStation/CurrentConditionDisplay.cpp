#include "pch.h"
#include "CurrentConditionDisplay.h"
#include <iostream>

using namespace std;

CCurrentConditionDisplay::CCurrentConditionDisplay(IObservable<WeatherInfo> &observable)
	: m_observable(observable)
{
	m_observable.RegisterObserver(*this);
}

CCurrentConditionDisplay::~CCurrentConditionDisplay()
{
	m_observable.RemoveObserver(*this);
}

void CCurrentConditionDisplay::Update(const WeatherInfo &weatherCondition)
{
	cout << "Current condition:\n";
	cout << "  temperature: " << weatherCondition.temperature << endl;
	cout << "  humidity: " << weatherCondition.humidity << endl;
	cout << "  pressure: " << weatherCondition.pressure << endl;
}