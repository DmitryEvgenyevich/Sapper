#pragma once
#include <string>

class Button
{
public:
	Button();
	Button(std::string, int, int);
	~Button();
	void printButton(ConsoleColor message = White, ConsoleColor background = Black);

private:
	std::string text;
	int x;
	int y;
};
