#include <windows.h>
#include <iostream>
#include "Console.h"
#include "Button.h"

Button::Button()
{
	text = "";
}

Button::Button(std::string text_)
{
	text = text_;
}

Button::~Button() 
{
}

void Button::printButton(int x, int y)
{
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
}