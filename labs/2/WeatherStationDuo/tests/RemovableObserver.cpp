#include "pch.h"
#include "RemovableObserver.h"

void CRemovableObserver::Update(const WeatherInfo &weatherInfo, ObservableType observableType)
{
	if (observableType == ObservableType::In)
	{
		RemoveFromInObservable();
	}
	else
	{
		RemoveFromOutObservable();
	}
}