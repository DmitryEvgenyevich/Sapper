#include "Console.h"
#include "Play.h"
#pragma comment(lib, "winmm.lib")

void Field::win()
{
	std::string text;
	text = "VICTORY";
	setPosition(middleX - text.size() / 2, 7);
	std::cout << text;

	text = "Press Esc";
	setPosition(middleX - text.size() / 2, 9);
	std::cout << text;

	PlaySound(TEXT("salo.wav"), NULL, SND_SYNC);
	
	while (_getch() != escape) {}

	system("cls");
}

int Field::bombCheck()
{
	for (int i{}; i < h; i++)
	{
		for (int j{}; j < w; j++)
		{
			if (field[i][j] < Bomb + CheckBox && field[i][j] != Bomb)
				return 1;
		}
	}
	return 0;
}

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

void Field::PrintAllBomb(const int x, const int y)
{
	PlaySound(TEXT("bomb.wav"), NULL, SND_FILENAME | SND_ASYNC);

	for (int i{}; i < h; i++)
		{
			for (int j{}; j < w; j++)
			{
				if (field[i][j] == FieldLabels::Bomb)
				{
					setPosition(j * 3 - 1 + x, i + y);
					std::cout << " * ";
					//Sleep(rand() % 1000 + 200);
				}
			}
		}
}

void Field::NullB(int x, int y, int k, int n)
{
	setPosition(--x, y);
	std::cout << "   ";
	field[k][n] += FieldLabels::Open;
	setPosition(++x, y);

	for (int i{ k - 1 }, y1{y - 1}; i < k + 2; i++, y1++)
	{
		for (int j{ n - 1 }, x1{x - 3}; j < n + 2; j++, x1+=3)
		{
			if (i < 0 || j < 0 || i == k && j == n || i >= h || j >= w || field[i][j] - FieldLabels::Open >= FieldLabels::NullB)
				continue;
			else if (field[i][j] == 0)
				Field::NullB(x1, y1,i, j);
			else
			{
				setPosition(x1-1, y1);
				std::cout << " " << field[i][j] << " ";
				field[i][j] += FieldLabels::Open;
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

void Field::printField(int x_, int y_)
{
	int x{ x_ }, y{ y_ };
	middleX = x + (wForPrintField + 1) / 2;

	setPosition(x_, y_);

	for (int i{}; i < wForPrintField; i++)
		std::cout << "*";
	setPosition(x_, ++y_);

	for (int i{}; i < h; i++)
	{
		for (int j{}; j < w + 2; j++)
		{
			if (j == 0 || j == w + 1)
				std::cout << "*";
			else
				std::cout << "[ ]";
		}
		setPosition(x_, ++y_);
	}

	for (int i{}; i < wForPrintField; i++)
		std::cout << "*";

	setPosition(x + 2, y + 1);
}

void Field::loss(const int x, const int y, int x_, int y_)
{
	std::string text;
	
	setPosition(--x_, y_);
	std::cout << " * ";
	setPosition(++x_, y_);
	
	text = "DEFEAT";
	setPosition(middleX - text.size() / 2, 7);
	std::cout << text;

	text = "Press Esc";
	setPosition(middleX - text.size() / 2, 9);
	std::cout << text;

	Field::PrintAllBomb(x, y);
	while (_getch() != KeyboardKeys::escape) {}

	system("cls");
}

void Field::Play()
{
	const int x{ getPositionX() };
	const int y{ getPositionY() };
	int x_{ x };
	int y_{ y };

	int i{}, j{};
	while (bombCheck())
	{
		switch (_getch())
		{
		case KeyboardKeys::UpArrow:
		{
			if (y_ > y)
			{
				setPosition(x_, --y_);
				--i;
			}
			break;
		}
		case KeyboardKeys::DownArrow:
		{
			if (y_ < y + h - 1)
			{
				setPosition(x_, ++y_);
				++i;
			}
			break;
		}

		case KeyboardKeys::LeftArrow:
		{
			if (x_ > x)
			{
				setPosition(x_ -= 3, y_);
				--j;
			}
			break;
		}

		case KeyboardKeys::RightArrow:
		{
			if (x_ < w * 3 + x - 3)
			{
				setPosition(x_ += 3, y_);
				++j;
			}
			break;
		}

		case KeyboardKeys::Space:
		{
			if (field[i][j] < FieldLabels::CheckBox)
			{
				field[i][j] += FieldLabels::CheckBox;
				std::cout << "&";
			}
			else if (field[i][j] >= FieldLabels::CheckBox && field[i][j] < FieldLabels::Open)
			{
				field[i][j] -= FieldLabels::CheckBox;
				std::cout << " ";
			}
			setPosition(x_, y_);
			break;
		}

		case KeyboardKeys::escape:
		{

			break;
		}
		case KeyboardKeys::Enter:
		{
			if (field[i][j] > FieldLabels::Bomb)
				PlaySound(TEXT("no.wav"), NULL, SND_FILENAME | SND_ASYNC);
			else if (field[i][j] == FieldLabels::Bomb)
			{
				loss(x, y, x_, y_);
				return;
			}

			else if (field[i][j] > FieldLabels::NullB)
			{
				setPosition(--x_, y_);
				std::cout << " " << field[i][j] << " ";
				field[i][j] += FieldLabels::Open;
				PlaySound(TEXT("povezlo.wav"), NULL, SND_ASYNC);
				setPosition(++x_, y_);
			}
			else if (field[i][j] == 0)
			{
				PlaySound(TEXT("povezlo.wav"), NULL, SND_ASYNC);
				Field::NullB(x_, y_, i, j);
			}
			break;
		}
		default:
			break;
		}
	}
	win();
}

