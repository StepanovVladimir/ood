#pragma once

#include "WeatherObserverOut.h"

class CCurrentConditionDisplayOut : public CWeatherObserverOut
{
private:
	void Update(const WeatherInfoOut &weatherInfo) override;
};