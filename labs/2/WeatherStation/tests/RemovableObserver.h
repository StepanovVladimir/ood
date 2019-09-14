#pragma once

#include "../WeatherStation/Observer.h"
#include "../WeatherStation/WeatherInfo.h"

class CRemovableObserver : public CObserver<WeatherInfo>
{
private:
	void Update(const WeatherInfo &weatherInfo) override;
};