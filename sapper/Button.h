#pragma once
#include <string>

class Button
{
public:
	Button();
	Button(std::string);
	~Button();
	void printButton(int, int, ConsoleColor message = White, ConsoleColor background = Black);

private:
	std::string text;
};
