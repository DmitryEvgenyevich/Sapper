#include "ButtonClass.h"
#include <vector>
#include <fstream>
#include <iostream>

std::vector<Button> buttons;

void buttonPlay()
{
	return;
}

void buttonExit()
{
	exit(1);
}

void levelEasy()
{
	std::ofstream fout;
	fout.open("Easy.lvl");

	if (!fout)
	{
		std::cerr << "File open failed...";
		exit(1);
	}

	fout << "5 16 10";
}

void levelNormal()
{
	std::ofstream fout;
	fout.open("Normal.lvl");

	if (!fout)
	{
		std::cerr << "File open failed...";
		exit(1);
	}

	fout << "9 28 40";
}

void levelHard()
{
	std::ofstream fout;
	fout.open("Hard.lvl");

	if (!fout)
	{
		std::cerr << "File open failed...";
		exit(1);
	}

	fout << "9 28 40";
}

Button startFirstPage()
{
	creationButons("Play", 0, 0, buttonPlay, buttons);
	creationButons("Exit", 0, 4, buttonExit, buttons);
	Button pressedB = buttonSelection(buttons);
	buttons.clear();
	system("cls");
	return pressedB;
}

Button startSecondPage()
{
	creationButons("Easy", 0, 0, levelEasy, buttons);
	creationButons("Normal", 0, 4, levelNormal, buttons);
	creationButons("Hard", 0, 8, levelHard, buttons);
	Button pressedB = buttonSelection(buttons);
	buttons.clear();
	system("cls");
	return pressedB;
}

int main()
{
	while (true)
	{
		Button pressedB = startFirstPage();
		pressedB.callFun();
		
		pressedB = startSecondPage();
		pressedB.callFun();


	}
}