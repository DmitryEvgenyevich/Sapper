#include "ButtonClass.h"
#include "Play.h"
#include <vector>
#include <fstream>
#include <iostream>

std::vector<Button> buttons;

int** field;
int H;
int W;
int B;

void buttonPlay()
{
	return;
}

void buttonExit()
{
	exit(1);
}

void buttonLevelEasy()
{
	//fout.open("Easy.lvl");
	//if (!fout)
	//{
	//	std::cerr << "File open failed...";
	//	exit(1);
	//}
	//fout << "5 16 10";
	
	field = createField(5, 16, 10);
	H = 8;
	W = 10;
	B = 10;
	field = createField(H, W, B);

}

void buttonLevelNormal()
{
	//fout.open("Normal.lvl");
	//if (!fout)
	//{
	//	std::cerr << "File open failed...";
	//	exit(1);
	//}
	//fout << "9 28 40";
	
	field = createField(9, 28, 40);
	H = 14;
	W = 18;
	B = 40;
	field = createField(H, W, B);
	
}

void buttonLevelHard()
{
	/*fout.open("Hard.lvl");

	if (!fout)
	{
		std::cerr << "File open failed...";
		exit(1);
	}

	fout << "12 40 99";*/
	H = 20;
	W = 24;
	B = 90;
	field = createField(H, W, B);
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
	creationButons("Easy", 0, 0, buttonLevelEasy, buttons);
	creationButons("Normal", 0, 4, buttonLevelNormal, buttons);
	creationButons("Hard", 0, 8, buttonLevelHard, buttons);
	Button pressedB = buttonSelection(buttons);
	buttons.clear();
	system("cls");
	return pressedB;
}

void logicGame()
{
	int x, y;
	setPosition(0, 0);
	printFieled(H, W, x, y);
	getPresButton(H, W, x, y);
}

int main()
{
	while (true)
	{
		Button pressedB = startFirstPage();
		pressedB.callFun();
		
		pressedB = startSecondPage();
		pressedB.callFun();

		logicGame();
	}
}