//*************************************************************
//  File: ConsoleLayer.h
//  Date created: 1/16/2016
//  Date edited: 3/22/2016
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
	/*********************************{
		@cl: ConsoleLayer
		@d: Cross-platform library for common console functions such as color manipulation, 
		cursor positioning, and getting raw keypress data.
	}*********************************/
	class ConsoleLayer
	{
		private:
			int m_storedX;
			int m_storedY;
		
		public:
			// color values
			static const int BLACK = 0; //{ @cnst: static const int BLACK }
			static const int RED = 1; //{ @cnst: static const int RED }
			static const int GREEN = 2; //{ @cnst: static const int GREEN }
			static const int YELLOW = 3; //{ @cnst: static const int YELLOW }
			static const int BLUE = 4; //{ @cnst: static const int BLUE }
			static const int MAGENTA = 5; //{ @cnst: static const int MAGENTA }
			static const int CYAN = 6; //{ @cnst: static const int CYAN }
			static const int WHITE = 7; //{ @cnst: static const int WHITE @d: This represents 'silver', not white. }
			static const int LIGHTBLACK = 8; //{ @cnst: static const int LIGHTBLACK @d: This represents 'dark grey'. }
			static const int LIGHTRED = 9; //{ @cnst: static const int LIGHTRED }
			static const int LIGHTGREEN = 10; //{ @cnst: static const int LIGHTGREEN }
			static const int LIGHTYELLOW = 11; //{ @cnst: static const int LIGHTYELLOW }
			static const int LIGHTBLUE = 12; //{ @cnst: static const int LIGHTBLUE }
			static const int LIGHTMAGENTA = 13; //{ @cnst: static const int LIGHTMAGENTA }
			static const int LIGHTCYAN = 14; //{ @cnst: static const int LIGHTCYAN }
			static const int LIGHTWHITE = 15; //{ @cnst: static const int LIGHTWHITE @d: This is actually white! }

			// TODO: Need constructor to set initial values for m_storedX and m_storedY?
			/*ConsoleLayer();
			~ConsoleLayer();*/

			// color
			
			/*********************************{
				@f: void setFGColor
				@d: Changes the foreground color at the cursor.
				@i: @v: int color @d: Color constant, use values in the constant list above.
			}*********************************/
			void setFGColor(int color);
			
			/*********************************{
				@f: void setBGColor
				@d: Changes the background color at the cursor.
				@i: @v: int color @d: Color constant, use values in the constant list above.
			}*********************************/
			void setBGColor(int color); // dont' forget that in linux you can't set the bold colors as bg (anything over 7)

			// positioning
			
			/*********************************{
				@f: void setCursorPos
				@d: Moves the cursor to the passed x and y coordinates.
				@i: 
					@v: int x @d: Sets cursor column.
					@v: int y @d: Sets cursor row.
			}*********************************/
			void setCursorPos(int x, int y);
			
			/*********************************{
				@f: void getCursorPos
				@d: Sets passed x and y variables to the current cursor position.
				@i: 
					@v: int* x @d: POST: Will point to the current cursor column.
					@v: int* y @d: POST: Will point to the current cursor row.
				@o: The passed x and y pointers will point to the current coordinates of the cursor.
			}*********************************/
			void getCursorPos(int* x, int* y); 

			/*********************************{
				@f: void moveCursorDown
				@d: Moves cursor down a specified number of rows.
				@i: @v: int times @d: Number of rows to move down.
			}*********************************/
			void moveCursorDown(int times);
			
			/*********************************{
				@f: void moveCursorUp
				@d: Moves cursor up a specified number of rows.
				@i: @v: int times @d: Number of rows to move up.
			}*********************************/
			void moveCursorUp(int times);
			
			/*********************************{
				@f: void moveCursorLeft
				@d: Moves cursor left a specified number of cols.
				@i: @v: int times @d: Number of cols to move left.
			}*********************************/
			void moveCursorLeft(int times);
			
			/*********************************{
				@f: void moveCursorRight
				@d: Moves cursor right a specified number of cols.
				@i: @v: int times @d: Number of cols to move right.
			}*********************************/
			void moveCursorRight(int times);

			/*********************************{
				@f: void storeCursorPos
				@d: Internally stores current cursor position.
			}*********************************/
			void storeCursorPos();
			
			/*********************************{
				@f: void restoreCursorPos
				@d: Moves cursor to previously stored position. (MUST have previously stored position!) NOTE: This is buffer position, so keep in mind that if you've reached the end of the buffer and are printing out more things, the position will not be on the same CHARACTER as before, only the same place in the buffer.)
			}*********************************/
			void restoreCursorPos();

			// misc
			
			
			/*********************************{
				@f: void getConsoleSize
				@d: Sets passed width and height variables to the current buffer dimensions. NOTE: Buffer dimensions, not console window dimensions!
				@i: 
					@v: int* width @d: POST: Will point to the number of buffer columns.
					@v: int* height @d: POST: Will point to the number of buffer rows.
				@o: The passed width and height pointers will point to the dimensions of the console buffer.
			}*********************************/
			void getConsoleSize(int* width, int* height);
			
			/*********************************{
				@f: void clear
				@d: Clears the console buffer.
			}*********************************/
			void clear();

			/*********************************{
				@f: int getNextKeyPress
				@d: Puts the console in raw input mode until a key is hit, then returns that key code. (NOTE: This function hangs program operation until a key is hit.)
				@o: Returns the key code for pressed key. Note that this varies per operating system. For Windows, check <a href='https://msdn.microsoft.com/en-us/library/windows/desktop/dd375731(v=vs.85).aspx'>MSDN Virtual-Key Codes</a>. Linux is just weird....
			}*********************************/
			int getNextKeyPress(); 
	};
}

#endif // CONSOLE_LAYER_H
