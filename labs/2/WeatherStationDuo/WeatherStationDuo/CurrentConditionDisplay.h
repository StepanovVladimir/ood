#pragma once

#include "Observer.h"
#include "WeatherInfo.h"

class CCurrentConditionDisplay : public CObserver<WeatherInfo>
{
private:
	void Update(const WeatherInfo &weatherInfo, ObservableType observableType) override;
};