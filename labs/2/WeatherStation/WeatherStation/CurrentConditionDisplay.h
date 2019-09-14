#pragma once

#include "Observer.h"
#include "WeatherInfo.h"

class CCurrentConditionDisplay : public CObserver<WeatherInfo>
{
public:
	CCurrentConditionDisplay() = default;
	CCurrentConditionDisplay(IObservable<WeatherInfo> &observable);

private:
	void Update(const WeatherInfo &weatherCondition) override;
};