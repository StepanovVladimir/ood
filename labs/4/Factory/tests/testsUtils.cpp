#include "testsUtils.h"
#include <float.h>

bool RealNumbersIsEqual(double num1, double num2)
{
	return num1 - FLT_EPSILON < num2 && num1 + FLT_EPSILON > num2;
}

bool operator==(const Point& p1, const Point& p2)
{
	return RealNumbersIsEqual(p1.x, p2.x) && RealNumbersIsEqual(p1.y, p2.y);
}