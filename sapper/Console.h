#pragma once 
#include<string>

enum ConsoleColor
{
	Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray,
	LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White,
};

enum KeyboardKeys
{
	Backspace = 8,
	escape = 27,
	Space = 32,
	Enter = 13,
	UpArrow = 72,
	DownArrow = 80,
	LeftArrow = 75,
	RightArrow = 77,
};

void setColor(ConsoleColor, ConsoleColor);
void setPosition(int, int);
std::string intToStr(int);
void SetWindowSize(int, int);
int getPositionX();
int getPositionY();