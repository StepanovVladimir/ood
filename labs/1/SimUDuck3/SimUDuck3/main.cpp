﻿#include "pch.h"
#include "MallardDuck.h"
#include "RedheadDuck.h"
#include "RubberDuck.h"
#include "DecoyDuck.h"

using namespace std;

int main()
{
	CMallardDuck mallardDuck;

	mallardDuck.Display();
	mallardDuck.PerformQuack();
	mallardDuck.PerformFly();
	mallardDuck.PerformDance();
	mallardDuck.Swim();
	mallardDuck.PerformFly();

	mallardDuck.SetFlyBehavior(make_unique<FlyBehavior>(FlyRocketPowered));

	mallardDuck.PerformFly();
	mallardDuck.PerformFly();

	CRedheadDuck redheadDuck;

	redheadDuck.Display();
	redheadDuck.PerformQuack();
	redheadDuck.PerformFly();
	redheadDuck.PerformDance();
	redheadDuck.Swim();

	CRubberDuck rubberDuck;

	rubberDuck.Display();
	rubberDuck.PerformQuack();
	rubberDuck.PerformFly();
	rubberDuck.PerformDance();
	rubberDuck.Swim();

	CDecoyDuck decoyDuck;

	decoyDuck.Display();
	decoyDuck.PerformQuack();
	decoyDuck.PerformFly();
	decoyDuck.PerformDance();
	decoyDuck.Swim();

	return 0;
}