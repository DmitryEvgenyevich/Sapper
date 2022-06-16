#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include "Console.h"
#include "Button.h"

std::vector<Button> buttons;


void creationButons(std::string text, int x, int y, void(*fun)())
{
    Button b(text, x, y, fun);
    b.printButton();
    buttons.push_back(b);
}

void play()
{
    std::cout << "play";
}

void exit()
{
    exit();
}


void start()
{
    creationButons("Play", 0, 0, play);
    creationButons("Exit", 0, 4, exit);
	creationButons("Play", 0, 8, play);
	buttonSelection(buttons).fun();
}