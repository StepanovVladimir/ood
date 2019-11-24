#include "pch.h"
#include "GumballMachine.h"

using namespace std;

void TestGumballMachine(CGumballMachine& m)
{
	cout << m.ToString() << endl;

	m.InsertQuarter();
	m.TurnCrank();

	cout << m.ToString() << endl;

	m.InsertQuarter();
	m.EjectQuarter();
	m.TurnCrank();

	cout << m.ToString() << endl;

	m.InsertQuarter();
	m.TurnCrank();
	m.InsertQuarter();
	m.TurnCrank();
	m.EjectQuarter();

	cout << m.ToString() << endl;

	m.InsertQuarter();
	m.InsertQuarter();
	m.TurnCrank();
	m.InsertQuarter();
	m.TurnCrank();
	m.InsertQuarter();
	m.TurnCrank();

	cout << m.ToString() << endl;

	m.EjectQuarter();
	
	cout << m.ToString() << endl;
}


int main()
{
	CGumballMachine m(5);
	TestGumballMachine(m);
}