#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	unique_ptr<int> ui = make_unique<int>(4);
	int i = 5;
}