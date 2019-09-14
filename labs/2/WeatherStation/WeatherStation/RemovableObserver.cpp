#include "pch.h"
#include "RemovableObserver.h"

CRemovableObserver::CRemovableObserver(IObservable<WeatherInfo> &observable)
	: CObserver(observable)
{
}

void CRemovableObserver::Update(const WeatherInfo &weatherCondition)
{
	RemoveFromObservable();
}