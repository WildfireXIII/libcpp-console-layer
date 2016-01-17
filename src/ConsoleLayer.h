//*************************************************************
//  File: ConsoleLayer.h
//  Date created: 1/16/2016
//  Date edited: 1/16/2016
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
			static const BLACK = 0;
			static const RED = 1;
			static const GREEN = 2;
			static const YELLOW = 3;
			static const BLUE
			static const MAGENTA = 5;
			static const CYAN = 6;
			static const WHITE = 7;
			static const LIGHTBLACK = 8;
			static const LIGHTRED = 9;
			static const LIGHTGREEN = 10;
			static const LIGHTYELLOW = 11;
			static const LIGHTBLUE = 12;
			static const LIGHTMAGENTA = 13;
			static const LIGHTCYAN = 14;
			static const LIGHTWHITE = 15;

			ConsoleLayer();
			~ConsoleLayer();

			// color
			void setFGColor(int color);
			/*void setBGColor(int color); // dont' forget that in linux you can't set the bold colors as bg (anything over 7)

			// positioning
			void setCursorPos(int x, int y);
			void getCursorPos(int* x, int* y); // assigns into the passed x and y

			void moveCursorDown(int times);
			void moveCursorUp(int times);
			void moveCursorLeft(int times);
			void moveCursorRight(int times);

			void storeCursorPos();
			void restoreCursorPos();
			
			void clear();*/
	};
}

#endif // CONSOLE_LAYER_H
