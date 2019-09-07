#pragma once

#include <functional>

using FlyBehavior = std::function<void(size_t&)>;

void FlyWithWings(size_t &flightsNumber);
void FlyRocketPowered(size_t &flightsNumber);
void FlyNoWay(size_t &flightsNumber);