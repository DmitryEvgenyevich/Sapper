#include "ButtonClass.h"
#include "Play.h"
#include <vector>
#include <fstream>
#include <iostream>

std::vector<Button> buttons;

Field fieldOfPlay;

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
	fieldOfPlay.setField(8, 10, 10);
}

void buttonLevelNormal()
{
	fieldOfPlay.setField(14, 18, 40);
}

void buttonLevelHard()
{
	fieldOfPlay.setField(20, 24, 90);
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
	fieldOfPlay.printField(0, 0);
	while (1)
	{
		fieldOfPlay.getPresButton();
	}
	
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