#pragma once

#include "../WeatherStation/IObservable.h"
#include "../WeatherStation/WeatherInfo.h"

class CRemovableObserver : public IObserver<WeatherInfo>
{
public:
	CRemovableObserver();
	~CRemovableObserver();

private:
	bool RegisterOnObservable(IObservable<WeatherInfo> &observable) override;
	void RemoveFromObservable() override;

	void Update(const WeatherInfo &weatherInfo) override;

	IObservable<WeatherInfo> *m_observable;
};