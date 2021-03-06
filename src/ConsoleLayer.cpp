//*************************************************************
//  File: ConsoleLayer.cpp
//  Date created: 1/16/2016
//  Date edited: 1/18/2016
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

	// TODO: Take out all the hConsole handles and set that up in constructor? (might speed things up)
	// TODO: don't forget that buffer sizes are handled differently in linux, so need to account for that in whatever local code

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
			switch (color)
			{
				case BLACK:
					cout << "\033[0;30m";
				break;
				case RED:
					cout << "\033[0;31m";
				break;
				case GREEN:
					cout << "\033[0;32m";
				break;
				case YELLOW:
					cout << "\033[0;33m";
				break;
				case BLUE:
					cout << "\033[0;34m";
				break;
				case MAGENTA:
					cout << "\033[0;35m";
				break;
				case CYAN:
					cout << "\033[0;36m";
				break;
				case WHITE:
					cout << "\033[0;37m";
				break;
				case LIGHTBLACK:
					cout << "\033[1;30m";
				break;
				case LIGHTRED:
					cout << "\033[1;31m";
				break;
				case LIGHTGREEN:
					cout << "\033[1;32m";
				break;
				case LIGHTYELLOW:
					cout << "\033[1;33m";
				break;
				case LIGHTBLUE:
					cout << "\033[1;34m";
				break;
				case LIGHTMAGENTA:
					cout << "\033[1;35m";
				break;
				case LIGHTCYAN:
					cout << "\033[1;36m";
				break;
				case LIGHTWHITE:
					cout << "\033[1;37m";
				break;
			}

			return;
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
			switch (color)
			{
				case BLACK:
					cout << "\033[40m";
				break;
				case RED:
					cout << "\033[41m";
				break;
				case GREEN:
					cout << "\033[42m";
				break;
				case YELLOW:
					cout << "\033[43m";
				break;
				case BLUE:
					cout << "\033[44m";
				break;
				case MAGENTA:
					cout << "\033[45m";
				break;
				case CYAN:
					cout << "\033[46m";
				break;
				case WHITE:
					cout << "\033[47m";
				break;
				case LIGHTBLACK:
					cout << "\033[40m";
				break;
				case LIGHTRED:
					cout << "\033[41m";
				break;
				case LIGHTGREEN:
					cout << "\033[42m";
				break;
				case LIGHTYELLOW:
					cout << "\033[43m";
				break;
				case LIGHTBLUE:
					cout << "\033[44m";
				break;
				case LIGHTMAGENTA:
					cout << "\033[45m";
				break;
				case LIGHTCYAN:
					cout << "\033[46m";
				break;
				case LIGHTWHITE:
					cout << "\033[47m";
				break;
			}

			return;
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
			cout << "\033[" << y << ";" << x << "H";
		#endif // linux
	}

	void ConsoleLayer::getCursorPos(int* x, int* y)
	{
		#ifdef _WIN32
			HANDLE hConsole;
			hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

			CONSOLE_SCREEN_BUFFER_INFO curAttr;
			GetConsoleScreenBufferInfo(hConsole, &curAttr);

			*x = curAttr.dwCursorPosition.X;
			*y = curAttr.dwCursorPosition.Y;

			return;
		#endif // _WIN32
		
		#ifdef linux
		#endif // linux
	}
	
	void ConsoleLayer::moveCursorDown(int times)
	{
		#ifdef _WIN32
			int tempX = 0;
			int tempY = 0;

			this->getCursorPos(&tempX, &tempY);
			this->setCursorPos(tempX, tempY + times);
		#endif // _WIN32
		
		#ifdef linux
		#endif // linux
	}
	void ConsoleLayer::moveCursorUp(int times)
	{
		#ifdef _WIN32
			int tempX = 0;
			int tempY = 0;

			this->getCursorPos(&tempX, &tempY);
			this->setCursorPos(tempX, tempY - times);
		#endif // _WIN32
		
		#ifdef linux
		#endif // linux
	}
	void ConsoleLayer::moveCursorLeft(int times)
	{
		#ifdef _WIN32
			int tempX = 0;
			int tempY = 0;

			this->getCursorPos(&tempX, &tempY);
			this->setCursorPos(tempX - times, tempY);
		#endif // _WIN32
		
		#ifdef linux
		#endif // linux
	}
	void ConsoleLayer::moveCursorRight(int times)
	{
		#ifdef _WIN32
			int tempX = 0;
			int tempY = 0;

			this->getCursorPos(&tempX, &tempY);
			this->setCursorPos(tempX + times, tempY);
		#endif // _WIN32
		
		#ifdef linux
		#endif // linux
	}
	
	void ConsoleLayer::storeCursorPos()
	{
		#ifdef _WIN32
			this->getCursorPos(&m_storedX, &m_storedY);
		#endif // _WIN32
		
		#ifdef linux
		#endif // linux
	}
	void ConsoleLayer::restoreCursorPos()
	{
		#ifdef _WIN32
			this->setCursorPos(m_storedX, m_storedY);
		#endif // _WIN32
		
		#ifdef linux
		#endif // linux
	}

	void ConsoleLayer::getConsoleSize(int* width, int* height)
	{
		#ifdef _WIN32
			HANDLE hConsole;
			hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

			CONSOLE_SCREEN_BUFFER_INFO curAttr;
			GetConsoleScreenBufferInfo(hConsole, &curAttr);

			*width = curAttr.dwSize.X;
			*height = curAttr.dwSize.Y;

			return;
		#endif // _WIN32
		
		#ifdef linux
		#endif // linux
	}

	void ConsoleLayer::clear()
	{
		#ifdef _WIN32
			/*HANDLE hConsole;
			hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

			CONSOLE_SCREEN_BUFFER_INFO curAttr;
			GetConsoleScreenBufferInfo(hConsole, &curAttr);

			*width = curAttr.dwSize.X;
			*height = curAttr.dwSize.Y;*/

			// TODO: THIS IS THE CHEATING WAY OUT!!!
			// at some point do this: http://www.cplusplus.com/articles/4z18T05o/

			system("cls");
			return;
		#endif // _WIN32
		
		#ifdef linux
			cout << "\033[2J\033[1;1H";
		#endif // linux
	}

	// thanks to http://www.cplusplus.com/forum/articles/7312/#msg33734
	// linux thanks to http://ubuntuforums.org/showthread.php?t=554845
	int ConsoleLayer::getNextKeyPress()
	{
		#ifdef _WIN32
			// NOTE: THIS IS GETTING INPUT HANDLE, NOT OUTPUT!! Don't take this out when clean up the rest!
			HANDLE hConsole;
			hConsole = GetStdHandle(STD_INPUT_HANDLE);

			// get the current console mode for later restoration
			DWORD mode;
			GetConsoleMode(hConsole, &mode);

			// set console to raw input mode
			SetConsoleMode(hConsole, 0);

			// clear input
			FlushConsoleInputBuffer(hConsole);

			//wait for single key release
			INPUT_RECORD input;
			DWORD numInputsRead;

			do { ReadConsoleInput(hConsole, &input, 1, &numInputsRead); }
			while ((input.EventType != KEY_EVENT) || !input.Event.KeyEvent.bKeyDown);

			// restore console mode
			SetConsoleMode(hConsole, mode);
			
			return input.Event.KeyEvent.wVirtualKeyCode;
		#endif // _WIN32
		
		// NOTE: linux will not record ctrl's, alts, or shits, but rather alters the number when hit in combinatioon with something else
		#ifdef linux
			struct termios old_attr;
			struct termios new_attr;

			// get current tty attr for later restoration
			tcgetattr(STDIN_FILENO, &org_opts);

			// set up raw input mode
			new_attr = old_attr;
			new_attr.c_lflag &= ~(ICANON | ECHOE | ECHOK | ECHONL | ECHOPRT | ECHOKE | ICRNL);
			tcsetattr(STDIN_FILENO, TCSANOW, &new_attr);

			// get input
			char buf[1];
			read(0, (void*)buf, 1);

			// restore old settings
			tcsetattr(STDIN_FILENO, TCSANOW, &old_attr);
			
			return buf[0];
		#endif // linux
	}
}

#endif // CONSOLE_LAYER_CPP
