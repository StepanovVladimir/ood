#include "pch.h"
#include "RemovableObserver.h"

void CRemovableObserver::Update(const WeatherInfo &weatherInfo)
{
	RemoveFromObservable();
}