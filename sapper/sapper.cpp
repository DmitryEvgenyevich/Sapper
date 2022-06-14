#include <windows.h>
#include <iostream>
#include "Console.h"
#include "Button.h"

int main()
{
    Button b("Play");
    b.printButton(0, 0);
    Button a("Exit");
    a.printButton(0, 4);
}
