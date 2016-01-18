//*************************************************************
//  File: ConsoleLayer.cpp
//  Date created: 1/16/2016
//  Date edited: 1/17/2016
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

			WORD attr = 0;

			// retrieve current attributes to preserve background color
			CONSOLE_SCREEN_BUFFER_INFO curAttr;
			GetConsoleScreenBufferInfo(hConsole, &curAttr);

			// assign to attr whatever background stuff is already in curAttr
			if (curAttr.wAttributes & BACKGROUND_RED) { attr = attr | BACKGROUND_RED; }
			if (curAttr.wAttributes & BACKGROUND_BLUE) { attr = attr | BACKGROUND_BLUE; }
			if (curAttr.wAttributes & BACKGROUND_GREEN) { attr = attr | BACKGROUND_GREEN; }
			if (curAttr.wAttributes & BACKGROUND_INTENSITY) { attr = attr | BACKGROUND_INTENSITY; }
		
		
			switch (color)
			{
				case BLACK :
				break;
				case RED :
					attr = attr | FOREGROUND_RED;
				break;
				case GREEN :
					attr = attr | FOREGROUND_GREEN;
				break;
				case YELLOW :
					attr = attr | FOREGROUND_GREEN | FOREGROUND_RED;
				break;
				case BLUE :
					attr = attr | FOREGROUND_BLUE;
				break;
				case MAGENTA :
					attr = attr | FOREGROUND_BLUE | FOREGROUND_RED;
				break;
				case CYAN :
					attr = attr | FOREGROUND_BLUE | FOREGROUND_GREEN;
				break;
				case WHITE :
					attr = attr | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN;
				break;
				case LIGHTBLACK :
					attr = attr | FOREGROUND_INTENSITY;
				break;
				case LIGHTRED :
					attr = attr | FOREGROUND_RED | FOREGROUND_INTENSITY;
				break;
				case LIGHTGREEN :
					attr = attr | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
				break;
				case LIGHTYELLOW :
					attr = attr | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY;
				break;
				case LIGHTBLUE :
					attr = attr | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
				break;
				case LIGHTMAGENTA :
					attr = attr | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY;
				break;
				case LIGHTCYAN :
					attr = attr | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
				break;
				case LIGHTWHITE :
					attr = attr | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
				break;
			}

			SetConsoleTextAttribute(hConsole, attr);
			return;
		#endif // _WIN32

		#ifdef linux
		#endif // linux
	}

	void ConsoleLayer::setBGColor(int color)
	{
		#ifdef _WIN32
			HANDLE hConsole;
			hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

			WORD attr = 0;

			// retrieve current attributes to preserve foreground color
			CONSOLE_SCREEN_BUFFER_INFO curAttr;
			GetConsoleScreenBufferInfo(hConsole, &curAttr);

			// assign to attr whatever background stuff is already in curAttr
			if (curAttr.wAttributes & FOREGROUND_RED) { attr = attr | FOREGROUND_RED; }
			if (curAttr.wAttributes & FOREGROUND_BLUE) { attr = attr | FOREGROUND_BLUE; }
			if (curAttr.wAttributes & FOREGROUND_GREEN) { attr = attr | FOREGROUND_GREEN; }
			if (curAttr.wAttributes & FOREGROUND_INTENSITY) { attr = attr | FOREGROUND_INTENSITY; }
		
			switch (color)
			{
				case BLACK :
				break;
				case RED :
					attr = attr | BACKGROUND_RED;
				break;
				case GREEN :
					attr = attr | BACKGROUND_GREEN;
				break;
				case YELLOW :
					attr = attr | BACKGROUND_GREEN | BACKGROUND_RED;
				break;
				case BLUE :
					attr = attr | BACKGROUND_BLUE;
				break;
				case MAGENTA :
					attr = attr | BACKGROUND_BLUE | BACKGROUND_RED;
				break;
				case CYAN :
					attr = attr | BACKGROUND_BLUE | BACKGROUND_GREEN;
				break;
				case WHITE :
					attr = attr | BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN;
				break;
				case LIGHTBLACK :
					attr = attr | BACKGROUND_INTENSITY;
				break;
				case LIGHTRED :
					attr = attr | BACKGROUND_RED | BACKGROUND_INTENSITY;
				break;
				case LIGHTGREEN :
					attr = attr | BACKGROUND_GREEN | BACKGROUND_INTENSITY;
				break;
				case LIGHTYELLOW :
					attr = attr | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY;
				break;
				case LIGHTBLUE :
					attr = attr | BACKGROUND_BLUE | BACKGROUND_INTENSITY;
				break;
				case LIGHTMAGENTA :
					attr = attr | BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_INTENSITY;
				break;
				case LIGHTCYAN :
					attr = attr | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY;
				break;
				case LIGHTWHITE :
					attr = attr | BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY;
				break;
			}

			SetConsoleTextAttribute(hConsole, attr);
			return;
		#endif // _WIN32

		#ifdef linux
		#endif // linux
	}

	void ConsoleLayer::setCursorPos(int x, int y)
	{
		#ifdef _WIN32
			HANDLE hConsole;
			hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

			COORD pos = {x, y};
			SetConsoleCursorPosition(hConsole, pos);

			return;
		#endif // _WIN32
		
		#ifdef linux
		#endif // linux
	}
}

#endif // CONSOLE_LAYER_CPP
