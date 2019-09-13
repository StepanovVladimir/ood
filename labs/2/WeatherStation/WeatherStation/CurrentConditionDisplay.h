#pragma once

#include "IObserver.h"
#include "IObservable.h"
#include "WeatherInfo.h"

class CCurrentConditionDisplay : public IObserver<WeatherInfo>
{
public:
	CCurrentConditionDisplay(IObservable<WeatherInfo> &observable);
	~CCurrentConditionDisplay();

private:
	void Update(const WeatherInfo &weatherCondition) override;

	IObservable<WeatherInfo> &m_observable;
};