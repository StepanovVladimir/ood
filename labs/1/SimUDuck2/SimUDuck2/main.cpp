#include "pch.h"
#include "MallardDuck.h"
#include "RedheadDuck.h"
#include "RubberDuck.h"
#include "DecoyDuck.h"
#include "FlyRocketPowered.h"
#include <iostream>

using namespace std;

void PlayWithDuck(const CDuck &duck)
{
	duck.Display();
	duck.Quack();
	duck.Fly();
	duck.Dance();
	duck.Swim();
}

int main()
{
	CMallardDuck mallardDuck;
	PlayWithDuck(mallardDuck);

	mallardDuck.SetFlyBehavior(make_unique<CFlyRocketPowered>());
	mallardDuck.Fly();
	mallardDuck.Fly();

	CRedheadDuck redheadDuck;
	PlayWithDuck(redheadDuck);

	CRubberDuck rubberDuck;
	PlayWithDuck(rubberDuck);

	CDecoyDuck decoyDuck;
	PlayWithDuck(decoyDuck);

	return 0;
}
