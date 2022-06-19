#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include "Console.h"
#include "Play.h"

void printArr(int** arr, int h, int w)
{
	for (int i{}; i < h; i++)
	{
		for (int j{}; j < w; j++)
			std::cout << arr[i][j];
		std::cout << '\n';
	}
}

int** printNumForFiled(int** field, int h, int w)
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
	return field;
}

int** createField(int h, int w, int bomb)
{
	int x, y;

	int **field = new int*[h];
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

	return printNumForFiled(field, h, w);
}

void printFieled(int h, int w, int& x, int& y)
{
	for (int i{}; i < w * 3 + 2; i++)
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
	
	for (int i{}; i < w * 3 + 2; i++)
		std::cout << "*";

	x = 2;
	y = 1;
	setPosition(x, y);
}

void getPresButton(int h, int w, int& x, int& y)
{
	while (true)
	{
		switch (_getch())
		{
		case KeyboardKeys::UpArrow:
		{
			if (y > 1)
				setPosition(x, --y);
			break;
		}
		case KeyboardKeys::DownArrow:
		{
			if (y < h)
				setPosition(x, ++y);
			break;
		}
	
		case KeyboardKeys::LeftArrow:
		{
			if (x > 1)
				setPosition(x -= 3, y);
			break;
		}

		case KeyboardKeys::RightArrow:
		{
			if (x < w*3-1)
				setPosition(x += 3, y);
			break;
		}
		default:
			break;
		}
	}
}
