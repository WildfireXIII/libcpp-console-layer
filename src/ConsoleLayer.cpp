//*************************************************************
//  File: ConsoleLayer.cpp
//  Date created: 1/16/2016
//  Date edited: 1/16/2016
//  Author: Nathan Martindale
//  Copyright © 2016 Digital Warrior Labs
//  Description: Cross-platform console manipulation library
//*************************************************************

#ifndef CONSOLE_LAYER_CPP
#define CONSOLE_LAYER_CPP

#include "ConsoleLayer.h"

using namespace std;

namespace dwl
{
	void ConsoleLayer::greet()
	{
		cout << "Hello world!" << endl;
	}
}

#endif // CONSOLE_LAYER_CPP
