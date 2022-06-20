#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include "Console.h"
#include "Play.h"

void Field::NumForField()
{
	for (int i{}; i < h; i++)
	{
		for (int j{}; j < w; j++)
		{
			if (field[i][j] == 0)
			{
				for (int k{ i - 1 }; k <= i + 1; k++)
				{
					for (int r{ j - 1 }; r <= j + 1; r++)
					{
						if (k < 0 || r < 0 || k >= h || r >= w)
							continue;
						else if (field[k][r] == 9)
							field[i][j]++;
					}
				}
			}
		}
	}
}

void Field::createField()
{
	int x, y;

	field = new int* [h];
	for (int i{}; i < h; i++)
		field[i] = new int[w] {};

	for (int i{}; i < bomb; i++)
	{
		do
		{
			x = rand() % h;
			y = rand() % w;
		} while (field[x][y] != 0);
		field[x][y] = 9;
	}

	std::cout << "\n";

	Field::NumForField();
}

void Field::setField(int h_, int w_, int bomb_)
{
	h = h_;
	w = w_;
	bomb = bomb_;
	wForPrintField = w * 3 + 2;
	Field::createField();
}

void Field::printField(int x, int y)
{
	setPosition(x, y);

	for (int i{}; i < wForPrintField; i++)
		std::cout << "*";
	std::cout << '\n';

	for (int i{}; i < h; i++)
	{
		for (int j{}; j < w + 2; j++)
		{
			if (j == 0 || j == w + 1)
				std::cout << "*";
			else
				std::cout << "[ ]";
		}
		std::cout << '\n';
	}

	for (int i{}; i < wForPrintField; i++)
		std::cout << "*";

	setPosition(x + 2, y + 1);
}

void Field::getPresButton()
{
	int x{ getPositionX() };
	int y{ getPositionY() };
	int i{}, j{};
	while (true)
	{
		switch (_getch())
		{
		case KeyboardKeys::UpArrow:
		{
			if (y > 1)
			{
				setPosition(x, --y);
				--i;
			}
			break;
		}
		case KeyboardKeys::DownArrow:
		{
			if (y < h)
			{
				setPosition(x, ++y);
				++i;
			}
			break;
		}
	
		case KeyboardKeys::LeftArrow:
		{
			if (x > 1)
			{
				setPosition(x -= 3, y);
				--j;
			}
			break;
		}

		case KeyboardKeys::RightArrow:
		{
			if (x < w * 3 - 1)
			{
				setPosition(x += 3, y);
				++j;
			}
			break;
		}

		case KeyboardKeys::Space:
		{
			if (field[i][j] != 7)
			{
				field[i][j] = 7;
				std::cout << "&";
			}
			else if (field[i][j] == 7)
			{
				field[i][j] = 0;
				std::cout << " ";
			}
			setPosition(x, y);
			break;		
		}

		case KeyboardKeys::escape:
		{

		}

		case KeyboardKeys::Enter:
		{
			
		}

		default:
			break;
		}
	}
}
