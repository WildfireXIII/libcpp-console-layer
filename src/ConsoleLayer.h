//*************************************************************
//  File: ConsoleLayer.h
//  Date created: 1/16/2016
//  Date edited: 1/17/2016
//  Author: Nathan Martindale
//  Copyright © 2016 Digital Warrior Labs
//  Description: Cross-platform console manipulation library
//*************************************************************

#ifndef CONSOLE_LAYER_H
#define CONSOLE_LAYER_H

#include <iostream>

#ifdef _WIN32
	#include <windows.h>
#endif // _WIN32

#ifdef linux
	#include <unistd.h>
	#include <termios.h>
	#include <stdio.h>
#endif // linux

using namespace std;

namespace dwl
{
	class ConsoleLayer
	{
		private:
			int m_storedX;
			int m_storedY;
		
		public:
			// color values
			static const int BLACK = 0;
			static const int RED = 1;
			static const int GREEN = 2;
			static const int YELLOW = 3;
			static const int BLUE = 4;
			static const int MAGENTA = 5;
			static const int CYAN = 6;
			static const int WHITE = 7;
			static const int LIGHTBLACK = 8;
			static const int LIGHTRED = 9;
			static const int LIGHTGREEN = 10;
			static const int LIGHTYELLOW = 11;
			static const int LIGHTBLUE = 12;
			static const int LIGHTMAGENTA = 13;
			static const int LIGHTCYAN = 14;
			static const int LIGHTWHITE = 15;

			/*ConsoleLayer();
			~ConsoleLayer();*/

			// color
			void setFGColor(int color);
			void setBGColor(int color); // dont' forget that in linux you can't set the bold colors as bg (anything over 7)

			// positioning
			void setCursorPos(int x, int y);
			void getCursorPos(int* x, int* y); // assigns into the passed x and y

			void moveCursorDown(int times);
			void moveCursorUp(int times);
			void moveCursorLeft(int times);
			void moveCursorRight(int times);

			void storeCursorPos();
			void restoreCursorPos();

			// misc
			void getConsoleSize(int* width, int* height);
			void clear();

			int getNextKeyPress(); // waits for next key press and returns with key code?
	};
}

#endif // CONSOLE_LAYER_H
