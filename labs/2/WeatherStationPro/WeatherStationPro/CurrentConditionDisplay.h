#pragma once

#include "WeatherObserver.h"

class CCurrentConditionDisplay : public CWeatherObserver
{
private:
	void Update(double value, EventType eventType) override;
};