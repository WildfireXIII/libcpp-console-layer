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

	void ConsoleLayer::setFGColor(int color)
	{
		#ifdef _WIN32
			HANDLE hConsole;
			hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

			WORD attr;
		
			switch (color)
			{
				case BLACK :
					attr = 0;
				break;
				case RED :
					attr = FOREGROUND_RED;
				break;
				case GREEN :
					attr = FOREGROUND_GREEN;
				break;
				case YELLOW :
					attr = FOREGROUND_GREEN | FOREGROUND_RED;
				break;
				case BLUE :
					attr = FOREGROUND_BLUE;
				break;
				case MAGENTA :
					attr = FOREGROUND_BLUE | FOREGROUND_RED;
				break;
				case CYAN :
					attr = FOREGROUND_BLUE | FOREGROUND_GREEN;
				break;
				case WHITE :
					attr = FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN;
				break;
				case LIGHTBLACK :
					attr = FOREGROUND_INTENSITY;
				break;
				case LIGHTRED :
					attr = FOREGROUND_RED | FOREGROUND_INTENSITY;
				break;
				case LIGHTGREEN :
					attr = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
				break;
				case LIGHTYELLOW :
					attr = FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY;
				break;
				case LIGHTBLUE :
					attr = FOREGROUND_BLUE | FOREGROUND_INTENSITY;
				break;
				case LIGHTMAGENTA :
					attr = FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY;
				break;
				case LIGHTCYAN :
					attr = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
				break;
				case LIGHTWHITE :
					attr = FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
				break;
			}
		#endif // _WIN32

		#ifdef linux
		#endif // linux
	}

}

#endif // CONSOLE_LAYER_CPP
