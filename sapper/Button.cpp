#include <windows.h>
#include <iostream>
#include <conio.h>
#include "Console.h"
#include "Button.h"

Button::Button()
{
	text = "";
}

Button::Button(std::string text_, int x_, int y_, void (*fun_)())
{
	text = text_;
	x = x_;
	y = y_;
	fun = fun_;
}

Button::~Button() 
{
}

void Button::printButton(ConsoleColor message, ConsoleColor background)
{
	int y_{y};
	setColor(message, background);
	for (int i{}; i < 3; i++)
	{	
		setPosition(x, y_);
		for (int j{}; j < text.size() + 4; j++)
		{
			std::cout << "*";
			if (i == 1)
			{
				std::cout << " " << text << " *";
				break;
			}
		}
		y_++;
	}
	setColor();
}

Button buttonSelection(std::vector<Button> buttons)
{
	int num{};
	while (true)
	{
		if (num < 0)
			num = buttons.size() - 1;
		else if (num >= buttons.size())
			num = 0;

		buttons[num].printButton(Red);

		switch (_getch())
		{
		case KeyboardKeys::UpArrow:
		{	
			buttons[num].printButton();
			num--;
			break;
		}
		case KeyboardKeys::DownArrow:
		{
			buttons[num].printButton();
			num++;
			break;
		}
		case KeyboardKeys::Enter:
			return buttons[num];
		default:
			break;
		}
		
	}
}