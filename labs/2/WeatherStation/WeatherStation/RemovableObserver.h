#pragma once

#include "Observer.h"
#include "WeatherInfo.h"

class CRemovableObserver : public CObserver<WeatherInfo>
{
public:
	CRemovableObserver() = default;
	CRemovableObserver(IObservable<WeatherInfo> &observable);

private:
	void Update(const WeatherInfo &weatherCondition) override;
};