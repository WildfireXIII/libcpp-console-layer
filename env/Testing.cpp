//*************************************************************
//  File: Testing.cpp
//  Date created: 1/13/2016
//  Date edited: 1/15/2016
//  Author: Nathan Martindale
//  Copyright © 2016 Digital Warrior Labs
//  Description: 
//*************************************************************

#include <iostream>
#include <string>

#include "../src/ConsoleLayer.h"

using namespace std;
using namespace dwl;

int main()
{
	ConsoleLayer* cl = new ConsoleLayer();

	cout << "Hello world!" << endl;

	cl->setFGColor(ConsoleLayer.RED);

	cout << "Hello world!" << endl;
	return 0;
}
