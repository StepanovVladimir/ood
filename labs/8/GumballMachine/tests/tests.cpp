#define CATCH_CONFIG_MAIN
#include "../../../../catch2/catch.hpp"
#include "../GumballMachine/GumballMachine.h"
#include <sstream>

using namespace std;

TEST_CASE("Create empty gumball machine")
{
	ostringstream outStrm;
	CGumballMachine m(0, outStrm);

	outStrm << m.ToString();

	istringstream result(outStrm.str());
	string str;

	getline(result, str);
	CHECK(str == "Mighty Gumball, Inc.");
	getline(result, str);
	CHECK(str == "C++-enabled Standing Gumball Model #2016 (with state)");
	getline(result, str);
	CHECK(str == "Inventory: 0 gumballs");
	getline(result, str);
	CHECK(str == "Machine is sold out");
}

TEST_CASE("Create gumball machine with one gumball")
{
	ostringstream outStrm;
	CGumballMachine m(1, outStrm);

	outStrm << m.ToString();

	istringstream result(outStrm.str());
	string str;

	getline(result, str);
	getline(result, str);
	getline(result, str);
	CHECK(str == "Inventory: 1 gumball");
	getline(result, str);
	CHECK(str == "Machine is waiting for quarter");
}

TEST_CASE("Create gumball machine with several gumballs")
{
	ostringstream outStrm;
	CGumballMachine m(2, outStrm);

	outStrm << m.ToString();

	istringstream result(outStrm.str());
	string str;

	getline(result, str);
	getline(result, str);
	getline(result, str);
	CHECK(str == "Inventory: 2 gumballs");
	getline(result, str);
	CHECK(str == "Machine is waiting for quarter");
}

TEST_CASE("Insert quarter on sold out state")
{
	ostringstream outStrm;
	CGumballMachine m(0, outStrm);

	m.InsertQuarter();
	outStrm << m.ToString();
	
	istringstream result(outStrm.str());
	string str;

	getline(result, str);
	CHECK(str == "You can't insert a quarter, the machine is sold out");
	getline(result, str);
	getline(result, str);
	getline(result, str);
	CHECK(str == "Inventory: 0 gumballs");
	getline(result, str);
	CHECK(str == "Machine is sold out");
}

TEST_CASE("Eject quarter on sold out state")
{
	ostringstream outStrm;
	CGumballMachine m(0, outStrm);

	m.EjectQuarter();
	outStrm << m.ToString();

	istringstream result(outStrm.str());
	string str;

	getline(result, str);
	CHECK(str == "You can't eject, you haven't inserted a quarter yet");
	getline(result, str);
	getline(result, str);
	getline(result, str);
	CHECK(str == "Inventory: 0 gumballs");
	getline(result, str);
	CHECK(str == "Machine is sold out");
}

TEST_CASE("Turn crank on sold out state")
{
	ostringstream outStrm;
	CGumballMachine m(0, outStrm);

	m.TurnCrank();
	outStrm << m.ToString();

	istringstream result(outStrm.str());
	string str;

	getline(result, str);
	CHECK(str == "You turned but there's no gumballs");
	getline(result, str);
	CHECK(str == "No gumball dispensed");
	getline(result, str);
	getline(result, str);
	getline(result, str);
	CHECK(str == "Inventory: 0 gumballs");
	getline(result, str);
	CHECK(str == "Machine is sold out");
}

TEST_CASE("Eject quarter on no quarter state")
{
	ostringstream outStrm;
	CGumballMachine m(2, outStrm);

	m.EjectQuarter();
	outStrm << m.ToString();

	istringstream result(outStrm.str());
	string str;

	getline(result, str);
	CHECK(str == "You haven't inserted a quarter");
	getline(result, str);
	getline(result, str);
	getline(result, str);
	CHECK(str == "Inventory: 2 gumballs");
	getline(result, str);
	CHECK(str == "Machine is waiting for quarter");
}

TEST_CASE("Turn crank on no quarter state")
{
	ostringstream outStrm;
	CGumballMachine m(2, outStrm);

	m.TurnCrank();
	outStrm << m.ToString();

	istringstream result(outStrm.str());
	string str;

	getline(result, str);
	CHECK(str == "You turned but there's no quarter");
	getline(result, str);
	CHECK(str == "You need to pay first");
	getline(result, str);
	getline(result, str);
	getline(result, str);
	CHECK(str == "Inventory: 2 gumballs");
	getline(result, str);
	CHECK(str == "Machine is waiting for quarter");
}

TEST_CASE("Insert quarter on no quarter state")
{
	ostringstream outStrm;
	CGumballMachine m(2, outStrm);

	m.InsertQuarter();
	outStrm << m.ToString();

	istringstream result(outStrm.str());
	string str;

	getline(result, str);
	CHECK(str == "You inserted a quarter");
	getline(result, str);
	getline(result, str);
	getline(result, str);
	CHECK(str == "Inventory: 2 gumballs");
	getline(result, str);
	CHECK(str == "Machine is waiting for turn of crank");
}

TEST_CASE("Insert quarter on has quarter state")
{
	ostringstream outStrm;
	CGumballMachine m(2, outStrm);

	m.InsertQuarter();
	m.InsertQuarter();
	outStrm << m.ToString();

	istringstream result(outStrm.str());
	string str;

	getline(result, str);
	getline(result, str);
	CHECK(str == "You can't insert another quarter");
	getline(result, str);
	getline(result, str);
	getline(result, str);
	CHECK(str == "Inventory: 2 gumballs");
	getline(result, str);
	CHECK(str == "Machine is waiting for turn of crank");
}

TEST_CASE("Eject quarter on has quarter state")
{
	ostringstream outStrm;
	CGumballMachine m(2, outStrm);

	m.InsertQuarter();
	m.EjectQuarter();
	outStrm << m.ToString();

	istringstream result(outStrm.str());
	string str;

	getline(result, str);
	getline(result, str);
	CHECK(str == "Quarter returned");
	getline(result, str);
	getline(result, str);
	getline(result, str);
	CHECK(str == "Inventory: 2 gumballs");
	getline(result, str);
	CHECK(str == "Machine is waiting for quarter");
}

TEST_CASE("Turn crank on has quarter state when gumballs remained")
{
	ostringstream outStrm;
	CGumballMachine m(2, outStrm);

	m.InsertQuarter();
	m.TurnCrank();
	outStrm << m.ToString();

	istringstream result(outStrm.str());
	string str;

	getline(result, str);
	getline(result, str);
	CHECK(str == "You turned...");
	getline(result, str);
	CHECK(str == "A gumball comes rolling out the slot...");
	getline(result, str);
	getline(result, str);
	getline(result, str);
	CHECK(str == "Inventory: 1 gumball");
	getline(result, str);
	CHECK(str == "Machine is waiting for quarter");
}

TEST_CASE("Turn crank on has quarter state when gumballs ended")
{
	ostringstream outStrm;
	CGumballMachine m(1, outStrm);

	m.InsertQuarter();
	m.TurnCrank();
	outStrm << m.ToString();

	istringstream result(outStrm.str());
	string str;

	getline(result, str);
	getline(result, str);
	CHECK(str == "You turned...");
	getline(result, str);
	CHECK(str == "A gumball comes rolling out the slot...");
	getline(result, str);
	CHECK(str == "Oops, out of gumballs");
	getline(result, str);
	getline(result, str);
	getline(result, str);
	CHECK(str == "Inventory: 0 gumballs");
	getline(result, str);
	CHECK(str == "Machine is sold out");
}