#include <windows.h>
#include <iostream>
#include "Console.h"
#include "Button.h"
#include <vector>

std::vector<Button> buttons;

int main()
{
    Button b("Play", 0, 0);
    b.printButton();
    Button a("Exit", 0, 4);
    a.printButton();
}
