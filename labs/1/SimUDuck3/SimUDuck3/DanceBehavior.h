#pragma once

#include <functional>

using DanceBehavior = std::function<void()>;

void Waltz();
void Minuet();
void NoDance();