#pragma once

#include "WeatherObserverIn.h"

class CCurrentConditionDisplayIn : public CWeatherObserverIn
{
private:
	void Update(const WeatherInfoIn &weatherInfo) override;
};