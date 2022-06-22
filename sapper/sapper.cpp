#include "ButtonClass.h"
#include "Play.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <mmsystem.h>



std::vector<Button> buttons;

Field fieldOfPlay;

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

void buttonPlay()
{
	creationButons("Easy", 31, 5, buttonLevelEasy, buttons);
	creationButons("Normal", 30, 9, buttonLevelNormal, buttons);
	creationButons("Hard", 31, 13, buttonLevelHard, buttons);
	buttonSelection(buttons).callFun();
}

int main()
{
	srand(time(0));
	rand();
	while (true)
	{
		setPosition(32, 3);
		std::cout << "SAPPER";
		creationButons("Play", 31, 5, buttonPlay, buttons);
		creationButons("Exit", 31, 9, buttonExit, buttons);
		buttonSelection(buttons).callFun();		
		fieldOfPlay.printField(20, 10);
		fieldOfPlay.Play();
	}
}