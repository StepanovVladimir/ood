#pragma once

#include "WeatherObserver.h"

class CCurrentConditionDisplay : public CWeatherObserver
{
private:
	void Update(const WeatherInfo &weatherInfo) override;
};