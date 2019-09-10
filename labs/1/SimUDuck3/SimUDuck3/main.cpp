#include "pch.h"
#include "MallardDuck.h"
#include "RedheadDuck.h"
#include "RubberDuck.h"
#include "DecoyDuck.h"
#include <iostream>

using namespace std;

void PlayWithDuck(CDuck &duck)
{
	duck.Display();
	duck.PerformQuack();
	duck.PerformFly();
	duck.PerformDance();
	duck.PerformSwim();
}

int main()
{
	CMallardDuck mallardDuck;
	PlayWithDuck(mallardDuck);

	mallardDuck.SetFlyBehavior(FlyRocketPowered());
	mallardDuck.PerformFly();
	mallardDuck.PerformFly();

	CRedheadDuck redheadDuck;
	PlayWithDuck(redheadDuck);

	CRubberDuck rubberDuck;
	PlayWithDuck(rubberDuck);

	CDecoyDuck decoyDuck;
	PlayWithDuck(decoyDuck);

	return 0;
}