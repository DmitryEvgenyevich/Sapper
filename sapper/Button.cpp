#include <windows.h>
#include <iostream>
#include "Console.h"
#include "Button.h"

Button::Button()
{
	text = "";
}

Button::Button(std::string text_, int x_, int y_)
{
	text = text_;
	x = x_;
	y = y_;
}

Button::~Button() 
{
}

void Button::printButton(ConsoleColor message, ConsoleColor background)
{
	setColor(message, background);
	for (int i{}; i < 3; i++)
	{	
		setPosition(x, y);
		for (int j{}; j < text.size() + 4; j++)
		{
			std::cout << "*";
			if (i == 1)
			{
				std::cout << " " << text << " *";
				break;
			}
		}
		y++;
	}
	setColor();
}