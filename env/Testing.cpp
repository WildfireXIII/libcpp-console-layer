//*************************************************************
//  File: Testing.cpp
//  Date created: 1/16/2016
//  Date edited: 1/17/2016
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

	/*cl->setCursorPos(0,0);
	cout << "Now I'm at the top of the window!" << endl;
	cl->setCursorPos(10,10);
	cout << "Now I'm somewhere in the middle..." << endl;*/


	int posX = 0;
	int posY = 0;
	cl->getCursorPos(&posX, &posY);
	cout << "Before this statement, cursor was at x: " << posX << " y: " << posY << endl;

	cl->storeCursorPos();

	cl->moveCursorUp(7);
	cl->moveCursorRight(20);
	
	cl->moveCursorDown(2);
	cout << "DOWN";
	cl->moveCursorRight(5);
	cout << "RIGHT";
	cl->moveCursorUp(1);
	cout << "UP";
	cl->moveCursorLeft(10);
	cout << "LEFT";

	cl->restoreCursorPos();
	cout << "Back to normal!" << endl;

	int width = 0;
	int height = 0;
	cl->getConsoleSize(&width, &height);

	cout << "Console size - width: " << width << " height: " << height << endl;

	//cl->clear();

	for (int i = 0; i < 10; i++)
	{
		int key = cl->getNextKeyPress();
		cout << key << endl;
	}
	
	return 0;
}
