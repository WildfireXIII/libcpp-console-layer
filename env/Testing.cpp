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
	cl->setFGColor(cl->RED);
	cout << "Hello world!" << endl;
	cl->setFGColor(cl->GREEN);
	cout << "Hello world!" << endl;
	cl->setFGColor(cl->YELLOW);
	cout << "Hello world!" << endl;
	cl->setFGColor(cl->BLUE);
	cout << "Hello world!" << endl;
	cl->setFGColor(cl->MAGENTA);
	cout << "Hello world!" << endl;
	cl->setFGColor(cl->CYAN);
	cout << "Hello world!" << endl;
	cl->setFGColor(cl->WHITE);
	cout << "Hello world!" << endl;
	cl->setFGColor(cl->LIGHTBLACK);
	cout << "Hello world!" << endl;
	cl->setFGColor(cl->LIGHTRED);
	cout << "Hello world!" << endl;
	cl->setFGColor(cl->LIGHTGREEN);
	cout << "Hello world!" << endl;
	cl->setFGColor(cl->LIGHTYELLOW);
	cout << "Hello world!" << endl;
	cl->setFGColor(cl->LIGHTBLUE);
	cout << "Hello world!" << endl;
	cl->setFGColor(cl->LIGHTMAGENTA);
	cout << "Hello world!" << endl;
	cl->setFGColor(cl->LIGHTCYAN);
	cout << "Hello world!" << endl;
	cl->setFGColor(cl->LIGHTWHITE);
	cout << "Hello world!" << endl;

	cl->setFGColor(cl->WHITE);

	cl->setBGColor(cl->RED);
	cl->setFGColor(cl->LIGHTWHITE);
	cout << "Hello world!" << endl;

	
	
	cl->setFGColor(cl->WHITE);
	cl->setBGColor(cl->BLACK);
	return 0;
}
